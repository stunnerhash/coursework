#include<stdio.h>

int main(){
  int n, sum = 0; 
  scanf("%d", &n);
  for(int i = 0, x = 0; i < n; i++) {
    scanf("%d", &x);
    sum += x;
  }
  int nde = n*n-n;
  int ans = sum/nde+1;
  printf("%d\n", ans);
  return 0;
}
