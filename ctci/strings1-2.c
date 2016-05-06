#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1;
#define false 0;

bool isPermutation(char * str1, char * str2){
  if(strlen(str1) != strlen(str2)){
    return false; 
  }
  int freq[255];
  int a;
  for(a = 0; a < strlen(str1); a++){
    freq[str1[a]]++;
    freq[str2[a]]--; 
  }
  for(a = 0; a < strlen(str1); a++){
    if(freq[str1[a]] != 0){
      return false; 
    }
  }
  return true;
}

void main(int argc, char * argv[]){
  isPermutation(argv[1], argv[2]) ? printf("true") : printf("false");
}
