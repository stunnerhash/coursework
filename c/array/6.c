#include<stdio.h>
#define loop(i,n) for(int i = 0;i<n;i++)

int main(){
  int n; 
  printf("Enter size of array: \n");
  scanf("%d", &n);
  printf("Enter array elements: \n");
  int row[n] = {}, col[n] = {};  
  loop(i,n) loop(j,n) {
    int x = 0; scanf("%d", &x);
    row[i] +=x;
    col[j] += x;
  }
  loop(i,n) loop(j,n){
    if(row[i] == col[j]) {
      printf("\nRow: %d", i+1);
      printf("\nCol: %d", j+1);
      return 0;
    }
  }
  printf("\n");
  return 0;
}
