// Author: Sheng Yu
// Time: 02/02/2013
//
// C solution for problem 1.1 in Cracking the Coding Interview 5th eidtion.
// For this problem, it's critical to know whether the string is an ASCII
// string or an Unicode string. In the solution, we assume it is an ASCII
// string
//
// Test environment: gcc (GCC) 4.1.2 20080704 (Red Hat 4.1.2-52)
//
 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
 
bool isUnique(char *str){
    int index = -1;
    char mask[32];
 
    if(str == NULL){
        // A null string should be unique
        return true;
    }
 
    memset(mask,0,32);  // clear all the masks to 0
 
    // Scan the string and check whether it is unique
    while(str[++index] != '\0'){
	printf("str[index]         :%c\n",str[index]);
	printf("str[index]         :%d\n",str[index]);
	printf("str[index]/8       :%d\n",str[index]/8);
	printf("str[index]%8       :%d\n",str[index]%8);
	printf("mask[str[index]/8] :%d\n",mask[str[index]/8]);
	printf("1<<(str[index]%8)  :%d\n",1<<(str[index]%8));
	printf("----------------------------------------------\n");
        if((mask[str[index]/8] & (1<<(str[index]%8))) != 0)
            return false;
        else
            mask[str[index]/8] |= 1<<(str[index]%8);
    }

    for (int index = 0; index<32; index++) {
        printf("%d,%c|",mask[index],mask[index]);
    }
    printf("\n");
    return true;
}
 
int main(int argc, char *argv[]){
    // Firstly check the arguments
    if(argc != 2){
        printf("Invalid arguments.n\n");
        printf("Usage: %s test_stringn\n",argv[0]);
        return 1;
    }
    // Use the argument as test string
    bool testret = isUnique(argv[1]);
    if(testret == true)
        printf("%s: is unique.n\n",argv[1]);
    else
        printf("%s: is not unique.n\n",argv[1]);
    return 0;
}
