#include<stdio.h>
#include<math.h>
#include<limits.h>

int max(int a, int b){
  return a>b ? a:b;
}

int equal(int a, int b){
  return a == b;
}
int main(){
  int n; 
  printf("Enter size of array:\n");
  scanf("%d", &n);
  printf("Enter array elements:\n");
  int a[n][n];
  int ans = 1;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n;j++)
      scanf("%d", &a[i][j]);

  for(int i = 0;i<n;i++){
    if(n == 1) break;
    if(i >0 && i< n-1) {
        ans = ans & 
        equal(
          a[i][i], 
          a[i-1][i]  + a[i][i-1] + a[i][i+1] +  a[i+1][i]
        );
    }else if(i == 0 && i<n-1){
      ans  = ans &
        equal(
          a[i][i], 
          a[i][i+1] + a[i+1][i] 
        );
    }else if(i > 0 && i == n-1){
      ans = ans &
        equal(
          a[i][i],
          a[i-1][i] + a[i][i-1]
        );
    }
  }

  printf(ans?"yes\n":"no\n");
  return 0;
}
