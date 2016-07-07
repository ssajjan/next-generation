// C++ program to reverse a string with special characters
#include<bits/stdc++.h>

using namespace std;
 
void checkP(char *str)
{
    printf("\n%s:address of string: %p\n",__func__,str);
    printf("str+1: %p, %c, %c \n",(str+1), (str+1),*(str+1));
}

void check(char str[])
{
    printf("\n%s:address of string: %p\n",__func__,str);
    printf("str+1: %p, %c, %c \n",(str+1), (str+1),*(str+1));
	
}
 
// Driver program
int main()
{
    char str[] = "abcd,e'f,ghi";
    cout << "Input string: " << str << endl;
    printf("address of string: %p\n",str);
    cout << "string len: " << strlen(str) << endl;
    cout << "string size: " << sizeof(str) << endl;
    printf("%p: %s\n",  (str),(str + 1));
    check(str);
    checkP(str);
    return 0;
}
