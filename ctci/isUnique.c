#include<stdio.h>
#include<stdlib.h>  // String and malloc function here
#include<stdbool.h> // bool
#include<stdint.h>  // uint32_t
#include<string.h>  // memset
#define MIN(a,b)  (a)<(b)?(a):(b)
#define MAX(a,b)  (a)>(b)?(a):(b)

bool flag[256] = {false};

bool isUnique_improved(char *string){

	//memset(flag, false, 256);
	printf("%s enter\n",__func__);
	if(strlen(string) > 256){
		printf("%s strlen is >256\n",__func__);
		return false;
	}

	int i = 0;
	while(string[i]){
		if(flag[string[i]])
			return false;
		else
			flag[string[i]] = true;
		i++;
	}
	return true;
}

//Below is the worst case as its time complexity is O(n2)
bool isUnique(char *string){

	int i=0,j=0;
	while(string[i]){
		j= i+1;
		while(string[j]){
			if(string[i]==string[j])
				return false;
			j++;
		}
		i++;
	}
	return true;
}

