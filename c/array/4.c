#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare (const void* num1, const void* num2){
  int a = *(int*) num1;
  int b = *(int*) num2;
  if(a>b) return 1;
  else if(a<b) return -1;
  else return 0;
}

void printUnique(int arr[], int n){
  qsort(arr, n, sizeof(int), compare);
  for(int i = 0;i<n; i++){
    if(i == n - 1){
      if(arr[i] != arr[i-1]) 
        printf("%d ", arr[i]);  
    }
    else if(arr[i] != arr[i+1]) 
      printf("%d ", arr[i]);  
  }
  printf("\n");
}

int main(){
  int n;
  scanf("%d", &n);
  int a[n][n];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n;j++)
      scanf("%d", &a[i][j]); 
 
  printf("Along rows\n");
  for(int i = 0;i<n;i++){
    int temp[n];
    for(int j = 0;j<n;j++)
      temp[j] = a[i][j];
    printUnique(temp, n);
  }
  
  printf("Along cols\n");
  for(int j = 0;j<n;j++) {
    int temp[n];
    for(int i = 0;i<n;i++)
      temp[i] = a[i][j];
    printUnique(temp, n);
  }

  printf("Along matrix\n");
  int temp[n*n];
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      temp[i*n + j] = a[i][j];
    }
  } 
  printUnique(temp,n*n);

  return 0;
}
