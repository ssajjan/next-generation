#define _XOPEN_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
#include <graphviz/cgraph.h>
#include <stdarg.h>

#define DEFAULT_NODES (5)
#define DEFAULT_EDGE_PROB (0.5)
#define DEFAULT_MAX_WEIGHT (50)
#define PADDING (5)

#define GET_ARG(name, type, argvector) do {\
    (name) = (type)strtoul(*(argvector), NULL, 0); \
    (argvector)++;\
} while(0)

void debug(bool print, const char *fmt, ...)
{
    va_list v_list;
    va_start(v_list, fmt);
    if (print)
    {
        printf("[debug]: ");
        vprintf(fmt, v_list);
    }
    va_end(v_list);
}

typedef struct graph_params {
    int nodes;
    double edge_prob;
    int weight_max;
    int directed;
} graph_params_t;

typedef struct graph_node {
    int num_name;
    Agnode_t *n;   
    char *name;
    int component;
}graph_node_t;

typedef struct graph_adj_matrix_elem
{
    double weight;
    Agedge_t *e;
    char *name_edge;
    int color;
}graph_adj_matrix_elem_t; 


typedef struct graph_adj_list_elem
{
    graph_node_t *adj_node;
    struct graph_adj_list_elem *next;   
} graph_adj_list_elem_t;

typedef int edge_color;
typedef struct graph_info {
    int nodes;
    graph_node_t *nodep;
    void *adj_matrix;
    void *adj_list;
    void *edge_colors;
    int *parent;
    Agraph_t *g;

    double edge_prob;
    int weight_max;
    int directed;
}graph_info_t; 

#define ALLOC_AND_CLEAR(x, nelems) do {\
    (x) = malloc(sizeof(*(x)) * (nelems));\
    memset(x, 0, sizeof(*x) * (nelems));\
    assert((x));\
} while(0)

void init_graph_info(graph_info_t **pgi, graph_params_t *gp)
{
    graph_adj_matrix_elem_t *adj;
    graph_adj_list_elem_t *adjl;

    graph_info_t *gi;
    edge_color  *edge;
    graph_node_t *node;
    int nodes;

    int i,j;

    ALLOC_AND_CLEAR(gi, 1);

    nodes = gi->nodes = gp->nodes;
    gi->edge_prob = gp->edge_prob;
    gi->weight_max = gp->weight_max;
    gi->directed = gp->directed;
    
    ALLOC_AND_CLEAR(gi->nodep, nodes);

    ALLOC_AND_CLEAR(adjl, nodes);
    gi->adj_list = adjl;


    ALLOC_AND_CLEAR(adj, nodes*nodes);
    gi->adj_matrix = adj;

    ALLOC_AND_CLEAR(edge, nodes*nodes);
    gi->edge_colors = edge;

    ALLOC_AND_CLEAR(gi->parent, nodes);
    for (i = 0; i < nodes; i++)
        gi->parent[i] = 'X' - 'a';
    graph_adj_matrix_elem_t (*adjmatrix)[nodes] = gi->adj_matrix;

    for (node = gi->nodep, i = 0; i < nodes; i++, node++)
    {
        node->num_name = i; 
        ALLOC_AND_CLEAR(node->name, 20); 
        snprintf(node->name, 20,"%c", node->num_name + 'a');
        adjl[i].adj_node = node;
        adjl[i].next = NULL;
    }

    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            char *s;
            ALLOC_AND_CLEAR(s, 20);
            adjmatrix[i][j].name_edge = s; 
        }
    }

    *pgi = gi;
}

void add_to_adj(graph_adj_list_elem_t *dst, graph_adj_list_elem_t *src)
{
    src->next = dst->next;
    dst->next = src;
}

void print_parents(graph_info_t *gi, bool debug_print)
{
    for (int i = 0; i < gi->nodes; i++)
    {
        debug(debug_print, "Parent of %c is %c\n", i + 'a', gi->parent[i] + 'a');
    }
}

void print_components(graph_info_t *gi, bool debug_print)
{
    for (int i = 0; i < gi->nodes; i++)
    {
        debug(debug_print, "Component of Node %c is %d\n", i + 'a', gi->nodep[i].component);
    }
}

void create_adjlist(graph_info_t *gi)
{
    int i, j;
    int nodes = gi->nodes;
    graph_adj_matrix_elem_t (*adjm)[nodes];
    graph_adj_list_elem_t *adjl;
    graph_node_t *nodep;
    graph_adj_list_elem_t *list;

    nodep = gi->nodep;
    adjm = gi->adj_matrix;
    adjl = gi->adj_list;

    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            if (!isinf(adjm[i][j].weight))
            {
                ALLOC_AND_CLEAR(list, 1);
                list->adj_node = &nodep[j];
                add_to_adj(&adjl[i], list);
            }  
        }
    } 
#if 0
    for (i = 0; i < nodes; i++)
    {
        list = adjl[i].next;
        printf("%s->", adjl[i].adj_node->name);
        while(list)
        {
            printf("%s->", list->adj_node->name);
            list = list->next;
        }
        printf("|\n");
    }
#endif
}

double drand48();
void *create_graph(graph_params_t *gp, bool display)
{
    graph_info_t *gi;
    int nodes = 0;
    int i, j;
    double randval;
    init_graph_info(&gi, gp);
    nodes = gi->nodes;

    graph_adj_matrix_elem_t (*adjm)[nodes];
    adjm = gi->adj_matrix;


    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            randval = drand48();            
            if (i == j)
            {
                randval = gi->edge_prob;   
            }

            if (randval > gi->edge_prob)
            {
                adjm[i][j].weight = randval * gi->weight_max;
            }
            else
            {
                adjm[i][j].weight = INFINITY;
            }
        }
    }

    if(display)
    {
        debug(display,"  ");
        for (i  = 0; i < nodes; i++)
        {
               debug(display,"%*c", PADDING, 'a'+i); 
        }

        debug(display,"\n");
        for (i  = 0; i < nodes; i++)
        {
            for( j = 0; j < PADDING; j++)
               debug(display,"-"); 
        }
    
        debug(display,"\n");

        for (i  = 0; i < nodes; i++)
        {
            debug(display,"%c|",'a' + i);
            for (j = 0; j < nodes; j++)
            {
                    debug(display,"%5.0f", adjm[i][j].weight);
            }
            debug(display,"\n");
        }
    }
    create_adjlist(gi);
    return gi;
}

#define EDGE_PROPS \
    X( red, =1, "red") \
    X( blue, ,"blue") \
    X( darkslategray, ,"darkslategray") \
    X( green2, ,"green2") 

#define X(a, e, b) a e,
enum {
    EDGE_PROPS
};
#undef X

#define X(a, e, b) b,
char *color_strings[] ={
    EDGE_PROPS
};
#undef X


void create_gv(graph_info_t *gi, bool hideold, bool showweights) 
{
    int i, j;
    Agraph_t *g;
    int nodes = gi->nodes; 
    graph_node_t *gn;
    edge_color (*edge)[nodes];
    graph_adj_matrix_elem_t (*adj_elm)[nodes] = gi->adj_matrix;
    gn = gi->nodep;
    edge = gi->edge_colors;

    g = agopen("G", Agstrictdirected, NULL);

    agattr(g, AGEDGE, "label", "");
    agattr(g, AGEDGE, "color", "black");
    agattr(g, AGEDGE, "weight", "1");
    agattr(g, AGEDGE, "style", "invis");
    agattr(g, AGNODE, "color", "black");
    agattr(g, AGRAPH, "rankdir", "LR"); 

    if(!g)
        assert(0);
    for (i = 0; i < nodes; i++)
    {
        gn[i].n = agnode(g, (char []){ 'a' + i, '\0'}, TRUE);
    }
     
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            Agedge_t *e;
            char *label = (char []){'a'+i,'a'+j, 0};
            e = agedge(g, gn[i].n, gn[j].n, label, TRUE);

            if (!isinf(adj_elm[i][j].weight))
            {
                char *w  = adj_elm[i][j].name_edge;
                memset(w, 0, 20);
                double val = 0;

                if (!hideold)
                    agset(e, "style", "");
                if (edge[i][j])
                {
                    agset(e, "color", color_strings[edge[i][j]]);
                    agattr(g, AGEDGE, "weight", "100");
                    agset(e, "style", "");

                }
                if (showweights)
                {
                    val =  adj_elm[i][j].weight;
                    sprintf(w, "%f", val);
                } 
                else
                {
                    val = edge[i][j];
                    sprintf(w, "%f", val);
                }
#if 0
                printf("%f %s\n", val, w);
#endif
                agset(e, "label", w);
            }
        }
    }
    agwrite(g, stdout);
    agclose(g);
    return ;
}

static int connected = 1;

bool *seen;
void dfs(graph_info_t *gi, int i, bool debug_flag)
{
    graph_adj_list_elem_t *adjl;
    graph_node_t *adj_node;
    int nodes = gi->nodes;
    edge_color  (*edges)[nodes] = gi->edge_colors;
    int num_name;
    adjl =  (graph_adj_list_elem_t *)gi->adj_list + i;
    seen[i] = true;

    adj_node = adjl->adj_node;
    num_name = adj_node->num_name;
    adj_node->component = connected;
    debug(debug_flag, "next: %s\n", adj_node->name);
    while((adjl = adjl->next))
    {
        adj_node = adjl->adj_node;
        num_name = adj_node->num_name;
        if (!seen[num_name])
        {
            edges[i][num_name] = connected;
            gi->parent[num_name] = i;
            create_gv(gi, false, true);
            dfs(gi, num_name, debug_flag);
        }
    }
}

void dfs_all(graph_info_t *gi, bool debug_flag)
{
    int nodes, i;
    nodes = gi->nodes;
    ALLOC_AND_CLEAR(seen, nodes);    
    for (i = 0; i < nodes; i++)
    {
        if (!seen[i])
        {
            dfs(gi, i, debug_flag);
            connected++;
            debug(debug_flag, "Connected components %d\n", connected);
        }
    }
}


int main(int argc, char **argv)
{
    bool debug_flag = false;
    int nodes;
    double edge_prob;
    int weight_max;
    bool randomize = false;
    long int seed = 0;
    graph_params_t gp;
    void *graph;

    edge_prob = DEFAULT_EDGE_PROB;
    nodes = DEFAULT_NODES;
    weight_max = DEFAULT_MAX_WEIGHT;
    seed = 0;
    memset(&gp, 0, sizeof(gp));

    argv++;
    while (*argv && *((*argv)++) == '-')
    {
        char option = **argv;
        argv++;
        switch (option)
        { 
            case 'n': 
            GET_ARG(nodes, int, argv);
            debug(debug_flag, "nodes : %d\n", nodes);
            break;

            case 'p':
            GET_ARG(edge_prob, double, argv);
            edge_prob /= 100;
            edge_prob = 1-edge_prob;
            debug(debug_flag, "edge_prob: %f\n", edge_prob);
            break;

            case 'w':
            GET_ARG(weight_max, int, argv);
            debug(debug_flag, "weight_max : %d\n", weight_max);
            break;

            case 's':
            GET_ARG(seed,long int, argv);
            debug(debug_flag, "seed: %ld\n", seed);
            case 'r':
            randomize = true;
            break;

            case 'd':
            debug_flag = !debug_flag;
            break;

            default:
            break;
        }

    }

    if (!seed && randomize)
    {
       seed = (long int)time(NULL); 
       debug(debug_flag, "seed: %ld\n", seed);
    }

    if (randomize)
       srand48(seed); 
     
    gp.nodes = nodes;
    gp.edge_prob = edge_prob;
    gp.weight_max = weight_max;
    gp.directed = false;

    graph = create_graph(&gp, debug_flag);

    create_gv(graph, false, true); 
    dfs_all(graph, debug_flag);
    create_gv(graph, true, true); 

    print_parents(graph, debug_flag);
    print_components(graph, debug_flag);
#if 0
    union_find(graph);
#endif
    (void)graph;
    (void)argc;
    (void)argv;
    return 0;
}
