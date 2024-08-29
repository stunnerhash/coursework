#include<stdio.h>
#include<math.h>
#include<limits.h>

int max(int a, int b){
  return a>b ? a:b;
}

int main(){
  int n; 
  printf("Enter size of array:\n");
  scanf("%d", &n);
  printf("Enter array elements:\n");
  int a[n][n];
  int ans[n], maxiIndex;
  int maxi = INT_MIN;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n;j++)
      scanf("%d", &a[i][j]);

  for(int i = 0;i<n;i++){
    ans[i] = 0;
    if(n == 1) break;
    if(i >0 && i< n-1) {
      ans [i] 
        = a[i-1][i-1]  + a[i-1][i] + a[i-1][i+1]
        + a[i][i-1] + a[i][i+1]
        + a[i+1][i-1] + a[i+1][i] + a[i+1][i+1];
    }else if(i == 0 && i<n-1){
      ans [i] 
        = a[i][i+1]
        + a[i+1][i] + a[i+1][i+1];
    }else if(i > 0 && i == n-1){
      ans [i] 
        = a[i-1][i] + a[i-1][i-1]
        + a[i][i-1];
    }
    maxi = max(maxi, ans[i]);     
  }

  // print answer
  for(int i = 0;i<n;i++){
    printf("%d: %d\n", a[i][i], ans[i]);
    if(ans[i] == maxi) maxiIndex = i;
  }
  printf("Index: %d\n", maxiIndex);
  return 0;
}
