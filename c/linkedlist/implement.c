#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<stdlib.h>  
#include<time.h>

#define BITS 3
#define N (1<<BITS)

int HEAD;
long long int arr[N];

long long int address(long long int x) 
{ 
  return x%N; 
}

long long int value(long long int x) 
{ 
  return x/N; 
}

void init();

int insert(int value);

int update(int pointer, int value);

void delete(int pointer);

void print_linked_list();

void print_array();

int main()
{
  srand(time(NULL)); 

  init();

  for(int i = 1; i<N; i++){
    insert(i*5);
    print_linked_list();
  }
  
  delete(address(arr[HEAD]));

  print_linked_list();
  
  return 0;
}

void init()
{
  memset(arr, -1, sizeof(arr));
  const int random = rand() % N;
  HEAD = random;
  printf("Head initialized at index: %d\n", HEAD);
}

int insert(int value)
{
  int head = HEAD;
  while(arr[head] != -1)
    head = address(arr[head]);
  // find a random empty location
  int new = rand()%N;
  while(arr[new] != -1 || new == head) 
    new = (new+1)%N;
  arr[head] = (value<<BITS) + new;
  return head;
}

int update(int pointer, int value)
{
  int head = HEAD;
  while(arr[head] != -1){
    if(head == pointer) break;
    head = address(arr[head]);
  } 
  if(arr[head] == -1) {
    printf("pointer couldn't be found");
  }
  int next = arr[head]%N;
  arr[head] = (value<<BITS) + next;
  return head;
}

void delete(int pointer)
{
  int head = HEAD;
  if(pointer == HEAD){
    printf("cannot delete the head of linked list\n");
    return;
  }
  if(arr[head] == -1){
    printf("pointer does not exist\n");
    return;
  }
  int next = address(arr[head]);  
  while(arr[next] != -1){
    if(next == pointer) break;
    head = next;
    next = address(arr[next]);
  } 
  arr[head] = (value(arr[head])<<BITS) + address(arr[next]);
  arr[next] = -1;
}

void print_linked_list()
{
  int head = HEAD;
  while(arr[head] != -1){
    printf("%d -> ", value(arr[head]));
    head = address(arr[head]);
  } 
  printf("null\n");
}

void print_array()
{
  for(int i = 0;i<N;i++) printf("%d: (value = %lld, next -> %lld) \n", i, arr[i]/N, arr[i]%N);
  printf("\n");
}



