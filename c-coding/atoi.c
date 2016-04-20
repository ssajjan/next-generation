#include <stdio.h>

int atoi(const char *str)
{
    if (*str == '\0')
       return 0;
 
    int res = 0;		// Initialize result
    int sign = 1;		// Initialize sign as positive
    int i = 0;			// Initialize index of first digit
 
     if (str[0] == '-')
    {
        sign = -1;
        i++;  			// Also update index of first digit
    }
 
    for (; str[i] != '\0'; ++i)
    {
        if ( str[i] <= '0' || str[i] >= '9')	// If string contain character it will terminate
            return 0; 
            
        res = res*10 + str[i] - '0';
    printf("asci of %c = %d, '0'=%d ", str[i],str[i],'0');
    printf("res[%d]=%d\n", i, res);
    }
 
    return sign*res;
}
 
int main()
{
    char str[] = "1iaasd234";
    
    printf("%d\n", atoi(str));
    
    return 0;
}

