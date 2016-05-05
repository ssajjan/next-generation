/* 
* Author: Santosh Sajjan
* Inetrval.c - main 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

/* An interval Struct to store start and end of an interval */
typedef struct Interval{
    int start, end;
}IntervalType;

/* Declaring Interval structure pointer to point to the list */
struct Interval *Intervals;
int number_of_intervals = 0;

/**********************Add*************************************************
* Add - takes two argument start and end of Interval.
*
* Add the interval [start,end] to existing interval list.
* Print message if the inetrval adder or Error message.
*
* RETURNS: nothing
*/
void Add(int start, int end){
		struct Interval *temp_Intervals = (struct Interval*)malloc(sizeof(struct Interval)*(number_of_intervals+3));
		int j=0, i=0;
		struct Interval temp = (struct Interval){start, end};
		for (i=0 ;i<number_of_intervals;i++){
			if(Intervals[i].start > end){  
				temp_Intervals[j++] = temp;
				temp = Intervals[i];
			}else if(Intervals[i].end < start){   
				temp_Intervals[j++] = Intervals[i];
				
			}else{  
				temp.start = MIN(Intervals[i].start, temp.start);
				temp.end = MAX(Intervals[i].end,temp.end);
			}
		}
		temp_Intervals[j++] = temp;
		number_of_intervals = j;
		free(Intervals);
		Intervals = temp_Intervals;
		printf("Successfully added inetrval [%d,%d]] and new # of intervals=%d \n",start,end,number_of_intervals);
}

/*************************Remove*******************************************
* Remove - takes two argument start and end of Interval.
*
* remove the interval [start,end] from existing interval list.
* Print message if the inetrval removed or Error message.
*
* RETURNS: nothing
*/
void Remove(int start, int end){
	struct Interval *temp_Intervals = (struct Interval*)malloc(sizeof(struct Interval)*(number_of_intervals+1));
	int j=0, i=0,start_removing=0, removed=0;
	
	if(Intervals[0].start >= end  || Intervals[number_of_intervals-1].end <= start)
			return;

	for(i=0;i<number_of_intervals;i++){
		if(Intervals[i].end <= start || Intervals[i].start >= end || removed){ 
			temp_Intervals[j++]=Intervals[i];
			if (Intervals[i].end == start){
				start_removing =1;
			}
			continue;
		}
		if(Intervals[i].start < start){ 
			temp_Intervals[j++] = (IntervalType){Intervals[i].start, start};
			start_removing = 1;
		}
		if((Intervals[i].end > end) && start_removing){ 
			temp_Intervals[j++] = (IntervalType){end, Intervals[i].end};
			removed=1;
		}
	}
	number_of_intervals = j;
	free(Intervals);
	Intervals=temp_Intervals;
	printf("Successfully removed inetrval [%d,%d]] and new # of intervals=%d \n",start,end,number_of_intervals);
}

/**************************************************************************
* printIntrevals - takes no argument.
* Print all intervals in the aaray of structure (Intervals) or print empty if list is empty.
* RETURNS: nothing
*/
void printIntrevals(){
	int i;
	if(number_of_intervals)
		printf("\n******************************************************************\
			\nNumber of intervals=%d\nInterval List:[",number_of_intervals);
	else
		printf("List is empty\n");
				
	for ( i = 0; i <number_of_intervals;i++){
		printf("[%d,%d]",Intervals[i].start, Intervals[i].end);		
		if(i == number_of_intervals-1)
			printf("]\n******************************************************************\n");
		else
			printf(",");
	}
	return;
}

/**************************************************************************
* main - takes no argument.
*
* This has the test logic to take input from user and call Add/Remove/printIntrevals functions accordingly.
*
* RETURNS: nothing
*/
int main(void){
	int start=1, end=2,x=0;
	
/*	remove below commented code to add 100 Intervals and check */
	int i;
	for (i=0;i<110+1;i++){
		Add(start,end); 
		start+=2;
		end+=2;
	}

	while(x != 99){
		printf ("\nEnter one of below choices\n1-->Add intervel\n2-->Remove intervel\n3-->Print Intervel list\n99 -->Exit\nchoice:");
		scanf ("%d",&x);

		if (x == 1){
			printf("Enter a pair of numbers to Add to Inetervel list:\n");
			scanf("%d %d",&start,&end); 
			if(start < end){
				Add(start, end);
				printIntrevals();
			}else{
				printf("Error: Wrong input start cannot be greater than end.\n");
			}
		} else if (x == 2){
			printf("Enter a pair of numbers to Remove from Inetervel list:\n");
			scanf("%d %d",&start,&end); 
			if(start < end){
				Remove(start,end);
				printIntrevals();
			}else{
				printf("Error: Wrong input start cannot be greater than end.\n");
			}
		}else if (x ==3){
			printIntrevals();
		}
		getchar();
    }
	return 0;
}
