#include <stdio.h>

typedef int bool;
#define false 0
#define true 1

struct Node {
  struct Node * next;
  int count;
  bool found;
  char * val;
};

struct Node kthToLast(int k, struct Node current){
  if(current.next){
    printf("test\n");
    struct Node next = kthToLast(k, *current.next);
    if(next.found == true) return next;
    current.count = next.count + 1;
  }
  printf("%a, %a\n", current.count, k);
  if(current.count == k) current.found = true;
  return current;
}

int main(){
  struct Node head;
  struct Node next1;
  struct Node next2;
  struct Node next3;
  struct Node next4;
  struct Node next5;
  struct Node next6;
  head.next = &next1;
  next1.next = &next2;
  next2.next = &next3;
  next3.next = &next4;
  next4.next = &next5;
  next5.next = &next6;
  head.val = "a";
  next1.val = "b";
  next2.val = "c";
  next3.val = "d";
  next4.val = "e";
  next5.val = "f";
  next6.val = "g";

  struct Node kth = kthToLast(4, head);
  printf("%s", kth.val);
  return 0;
}
