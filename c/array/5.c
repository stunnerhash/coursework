#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define loop(i,n) for (int i = 0;i<n;i++)

int compare(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

int main(){
  int n; 
  printf("Enter number of strings: \n");
  scanf("%d", &n);
  printf("Enter strings: \n");
  char c[n][50];
  loop(i,n) scanf("%s",&c[i]);
  qsort(c, n, sizeof(c[0]), compare);
  printf("Sorted:\n");
  loop(i,n) printf("%s ", c[i]);
  printf("Unique:\n");

  loop(i,n){
    if(i == n-1){
      if(strcmp(c[i], c[i-1]) != 0){
        printf("%s ", c[i]);
      } 
    }
    else if(strcmp(c[i], c[i+1]) != 0) {
      printf("%s ", c[i]);
    }
  }
  printf("\n");
  return 0;
}
