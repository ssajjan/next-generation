#include<stdio.h>

int main() {

  typedef  struct node {
         int data;
         struct node *link;
     }Node;

/*     struct node *p, *q;
     p = (struct node *) malloc(sizeof(struct node));
     q = (struct node *) malloc(sizeof(struct node));
     printf("%d, %d\n", sizeof(*p), sizeof(*q));
     printf("%zu, %zu\n", sizeof(*p), sizeof(*q));
	free(p);
	free(q);
*/

struct node p;// = (3, ((Node *)NULL));
struct node q = {4, &p};

printf("%zu, %zu\n", sizeof(p), sizeof(q));

     return 0;
}
