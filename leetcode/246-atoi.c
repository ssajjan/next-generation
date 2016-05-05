#include<stdio.h>
#include<stdlib.h>  // String and malloc function here
#include<stdbool.h> // bool
#include<stdint.h>  // uint32_t
#include<string.h>  // memset

#define MIN(a,b)  (a)<(b)?(a):(b)
#define MAX(a,b)  (a)>(b)?(a):(b)

int myAtoi(char* str) {

   if (*str == '\0')
      return 0;

   static const int MAX_INT = (int)((unsigned int)~0 >> 1);
   static const int MIN_INT = -(int)((unsigned int)~0 >> 1) - 1;
 
   int result = 0;			// Initialize result
   int sign = 1, signs=0;		// Initialize sign as positive
   int i = 0;			// Initialize index of first digit
 

   while(str[i]==' ' || str[i] == '-'|| str[i] == '+'){
     if (str[i] == '-'){
         sign = -1; signs++;
     }else if (str[i] == '+'){
	signs++;
     }else if(signs){
	signs++;
     }
     if(signs >1)
	return 0;
     i++;
   } 

   for (; str[i] != '\0'; ++i)
   {
      if ( str[i] < '0' || str[i] > '9')	// If string contain character it will terminate
   	return sign*result;

	// ssajjan-question:  how this is working to take care of overflow condition??     
      if(sign == 1 && (result > MAX_INT / 10 || (result == MAX_INT / 10 && (str[i] - '0') > MAX_INT % 10 ))) {
         return MAX_INT;
       } else if (sign == -1 && (result > (unsigned)MIN_INT / 10 || (result == (unsigned)MIN_INT / 10 && (str[i] - '0') > (unsigned)MIN_INT % 10 ))) {
         return MIN_INT;
       }
       result = result*10 + str[i] - '0';
   }
 
   return sign*result;
}
 

int main(int argc, char* argv[]){

	printf("This is test main func, atoi= %d\n",myAtoi("     +010"));
	printf("This is test main func, atoi= %d\n",myAtoi("     -010"));
	printf("This is test main func, atoi= %d\n",myAtoi("     + - - 010"));
	printf("This is test main func, atoi= %d\n",myAtoi("     - 010"));
	printf("This is test main func, atoi= %d\n",myAtoi("+-2"));
	printf("This is test main func, atoi= %d\n",myAtoi("2147483648"));
	printf("This is test main func, atoi= %d\n",myAtoi("   - 321"));
	
	return 0;
}

