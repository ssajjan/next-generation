#include<stdio.h>

#define BOOL(x) (!(!(x)))

#define BitSet(arg,posn) ((arg) | (1L << (posn)))
#define BitClr(arg,posn) ((arg) & ~(1L << (posn)))
#define BitTst(arg,posn) BOOL((arg) & (1L << (posn)))
#define BitFlp(arg,posn) ((arg) ^ (1L << (posn)))

int main()
{
bitmanip(10);
return 0;
}

int bitmanip(int word)
{
printf("fresh %d\n",word);
      word = BitSet(word, 2);
printf("set 2 %d\n",word);
      word = BitSet(word, 7);
printf("set 7 %d\n",word);
      word = BitClr(word, 3);
printf("clr 3 %d\n",word);
      word = BitFlp(word, 9);
printf("flip 9 %d\n",word);
      return word;
}


/*
#define BOOL(x) (!(!(x)))

#define BitSet(arg,posn) ((arg) | (1L << (posn)))
#define BitClr(arg,posn) ((arg) & ~(1L << (posn)))
#define BitTst(arg,posn) BOOL((arg) & (1L << (posn)))
#define BitFlp(arg,posn) ((arg) ^ (1L << (posn)))

int bitmanip(int word)
{
      word = BitSet(word, 2);
      word = BitSet(word, 7);
      word = BitClr(word, 3);
      word = BitFlp(word, 9);
      return word;
}*/
