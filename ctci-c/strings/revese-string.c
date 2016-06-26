//gcc -o revese-string revese-string.c --std=c99

#include<stdio.h>
#include<stdint.h>

void swap(char *s,char *d){

	char temp = *d;
	*d = *s;
	*s = temp;
}

uint32_t string_len(char * string){
	
	uint32_t i= 0;
	while(*(string+i) != '\0')
		i++;
	return i;
}


void reverseString(char *input_string){
	
	uint32_t len;
	char *begin, *end;
	begin=end=input_string;
	
	len = string_len(input_string);
	
	printf("len = %d\n", len);
	for(int i=0; i < len-1;i++)
		end++;

	for(int i=0;i<(len/2);i++){
		printf("begin = %p -> %c , end = %p-> %c\n",(void*)(begin+i),*(begin+i), (void *)(end-i),*(end-i));
		swap((begin+i), (end-i));
	}

}

int main(int argc, char *argv[])
{
	char string[11] = "hellhoware";
	printf("String: %s\n", string);
	reverseString(string);	
	printf("Reverse String: %s\n", string);
	
	return 0;
}
