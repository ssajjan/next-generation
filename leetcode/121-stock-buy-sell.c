#include<stdio.h>
#include<stdlib.h> // String and malloc function here
#include<stdbool.h> //bool
#include<stdint.h> // uint32_t

#define MIN(a,b)  (a)<(b)?(a):(b)
#define MAX(a,b)  (a)>(b)?(a):(b)

//This function returns -ve values if the stock is always going down.
int maxProfit(int* prices, int pricesSize) {

        int i=0;

        int min=prices[0], profit=(prices[1]-prices[0]),current_profit=0;

        if(pricesSize < 2)

                return 0;

        for(i=1;i<pricesSize;i++){

                current_profit= prices[i]-min;
                profit = MAX(profit,current_profit);
                min = MIN(prices[i],min);
        }
        return profit;
}


int main(int argc, char* argv[]){

	uint32_t number =10;

	int stock[10]= {890,322,70,42,34,25,23,17,11,0};
	printf("number = %d\n", number);
	
	maxProfit(stock,10);
		
	return 0;
}

