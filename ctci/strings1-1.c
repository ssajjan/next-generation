#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool isUniqueChars(char *str){
  bool char_set[256];
  if(strlen(str) > 256){ return false; }
    
  int i;
  for(i = 0; i < strlen(str); i++){
    if(char_set[str[i]] == true){
      return false;
    }
    char_set[str[i]] = true;
  }
  return true;
}

void main(int argc, char *argv[]){
  char * result = isUniqueChars(argv[1]) ? "true" : "false";
  printf("%s", result);
}
