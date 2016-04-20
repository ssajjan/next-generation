#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Interval{
    int start;
	int end;
    struct Interval *next;
};

struct Interval *head = NULL;
struct Interval *curr = NULL;

struct Interval* create_list(int start, int end){
    printf("\n creating list with intervel as [%d,%d]\n",start, end);
    struct Interval *ptr = (struct Interval*)malloc(sizeof(struct Interval));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->start = start;
	ptr->end = end;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;
}

struct Interval* insert_list(int start, int end,int i){
	printf("inserting list [%d,%d]\n",start,end);
	struct Interval temp;
	
	
}

int main(void){
	
	create_list(1,3)
	while(x != 4){
		printf ("\nEnter\n1-->Add intervel\n2-->Remove intervel\n3-->Print Intervel list\n4 -->Exit\ninput:");
		scanf ("%d",&x);

		if (x == 1){
			printf("Enter a pair of numbers to Add to Inetervel list:\n");
			scanf("%d %d",&start,&end); 
			if(start < end){
				Add(start, end);
				printIntrevals();
			}
				
			else 
				printf("Error: Wrong input start cannot be greater than end.\n");
					
		} else if (x == 2){
			printf("Enter a pair of numbers to Remove from Inetervel list:\n");
			scanf("%d %d",&start,&end); 
			if(start < end){
				Remove(start,end);
				printIntrevals();
			}
			else 
				printf("Error: Wrong input start cannot be greater than end.\n");
			
		}else if (x ==3){
			printIntrevals();
			
		}
    }
	
	return 0;
	
}