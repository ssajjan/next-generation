// red-black tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

//////////////////////
// supplied by user //
//////////////////////

typedef int KeyType;            // type of key

typedef struct {                // value related to key
    int stuff;
} ValType;

// how to compare keys
#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

/////////////////////////////////////
// implementation independent code //
/////////////////////////////////////

typedef enum {
    RBT_STATUS_OK,
    RBT_STATUS_MEM_EXHAUSTED,
    RBT_STATUS_DUPLICATE_KEY,
    RBT_STATUS_KEY_NOT_FOUND
} RbtStatus;

typedef enum { BLACK, RED } nodeColor;

typedef struct NodeTag {
    struct NodeTag *left;       // left child
    struct NodeTag *right;      // right child
    struct NodeTag *parent;     // parent
    nodeColor color;            // node color (BLACK, RED)
    KeyType key;                // key used for searching
    ValType val;                // data related to key
} NodeType;

#define SENTINEL &sentinel      // all leafs are sentinels
static NodeType sentinel = { SENTINEL, SENTINEL, 0, BLACK, 0};

static NodeType *root = SENTINEL; // root of red-black tree

static void rotateLeft(NodeType *x) {

    // rotate node x to left

    NodeType *y = x->right;

    // establish x->right link
    x->right = y->left;
    if (y->left != SENTINEL) y->left->parent = x;

    // establish y->parent link
    if (y != SENTINEL) y->parent = x->parent;
    if (x->parent) {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    } else {
        root = y;
    }

    // link x and y
    y->left = x;
    if (x != SENTINEL) x->parent = y;
}

static void rotateRight(NodeType *x) {

    // rotate node x to right

    NodeType *y = x->left;

    // establish x->left link
    x->left = y->right;
    if (y->right != SENTINEL) y->right->parent = x;

    // establish y->parent link
    if (y != SENTINEL) y->parent = x->parent;
    if (x->parent) {
        if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
    } else {
        root = y;
    }

    // link x and y
    y->right = x;
    if (x != SENTINEL) x->parent = y;
}

static void insertFixup(NodeType *x) {

    // maintain red-black tree balance
    // after inserting node x

    // check red-black properties
    while (x != root && x->parent->color == RED) {
        // we have a violation
        if (x->parent == x->parent->parent->left) {
            NodeType *y = x->parent->parent->right;
            if (y->color == RED) {

                // uncle is RED
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } else {

                // uncle is BLACK
                if (x == x->parent->right) {
                    // make x a left child
                    x = x->parent;
                    rotateLeft(x);
                }

                // recolor and rotate
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rotateRight(x->parent->parent);
            }
        } else {

            // mirror image of above code
            NodeType *y = x->parent->parent->left;
            if (y->color == RED) {

                // uncle is RED
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } else {

                // uncle is BLACK
                if (x == x->parent->left) {
                    x = x->parent;
                    rotateRight(x);
                }
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rotateLeft(x->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

// insert new node (no duplicates allowed)
RbtStatus rbtInsert(KeyType key, ValType val) {
    NodeType *current, *parent, *x;

    // allocate node for data and insert in tree

    // find future parent
    current = root;
    parent = 0;
    while (current != SENTINEL) {
        if (compEQ(key, current->key)) 
            return RBT_STATUS_DUPLICATE_KEY;
        parent = current;
        current = compLT(key, current->key) ?
            current->left : current->right;
    }

    // setup new node
    if ((x = malloc (sizeof(*x))) == 0)
        return RBT_STATUS_MEM_EXHAUSTED;
    x->parent = parent;
    x->left = SENTINEL;
    x->right = SENTINEL;
    x->color = RED;
    x->key = key;
    x->val = val;

    // insert node in tree
    if(parent) {
        if(compLT(key, parent->key))
            parent->left = x;
        else
            parent->right = x;
    } else {
        root = x;
    }

    insertFixup(x);

    return RBT_STATUS_OK;
}

static void deleteFixup(NodeType *x) {

    // maintain red-black tree balance
    // after deleting node x

    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            NodeType *w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft (x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rotateRight (w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rotateLeft (x->parent);
                x = root;
            }
        } else {
            NodeType *w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight (x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft (w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rotateRight (x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

// delete node
RbtStatus rbtErase(NodeType * z) {
    NodeType *x, *y;

    if (z->left == SENTINEL || z->right == SENTINEL) {
        // y has a SENTINEL node as a child
        y = z;
    } else {
        // find tree successor with a SENTINEL node as a child
        y = z->right;
        while (y->left != SENTINEL) y = y->left;
    }

    // x is y's only child
    if (y->left != SENTINEL)
        x = y->left;
    else
        x = y->right;

    // remove y from the parent chain
    x->parent = y->parent;
    if (y->parent)
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    else
        root = x;

    if (y != z) {
        z->key = y->key;
        z->val = y->val;
    }


    if (y->color == BLACK)
        deleteFixup (x);

    free (y);

    return RBT_STATUS_OK;
}

// find key
NodeType *rbtFind(KeyType key) {
    NodeType *current;
    current = root;
    while(current != SENTINEL) {
        if(compEQ(key, current->key)) {
            return current;
        } else {
            current = compLT (key, current->key) ?
                current->left : current->right;
        }
    }
    return NULL;
}

// in-order walk of tree
void rbtInorder(NodeType *p, void (callback)(NodeType *)) {
    if (p == SENTINEL) return;
    rbtInorder(p->left, callback);
    callback(p);
    rbtInorder(p->right, callback);
}

// delete nodes depth-first
void rbtDelete(NodeType *p) {
    if (p == SENTINEL) return;
    rbtDelete(p->left);
    rbtDelete(p->right);
    free(p);
}

void displayNode(NodeType *p) {
    printf("%d %d\n", p->key, p->val.stuff);
}

int main(int argc, char **argv) {
    int maxnum, ct;
    KeyType key;
    RbtStatus status;

    // command-line:
    //
    //   rbt 2000
    //      process 2000 records

    NodeType *p;

    maxnum = atoi(argv[1]);

    printf("maxnum = %d\n", maxnum);
    for (ct = maxnum; ct; ct--) {
        key = rand() % 90 + 1;
        if ((p = rbtFind(key)) != NULL) {
            if (p->val.stuff != 10*key) printf("fail val\n");
            status = rbtErase(p);
            if (status) printf("fail: status = %d\n", status);
        } else {
            ValType val;
            val.stuff = 10*key;
            status = rbtInsert(key, val);
            if (status) printf("fail: status = %d\n", status);
        }
    }

    // output nodes in order
    rbtInorder(root, displayNode);

    rbtDelete(root);

    return 0;
}
