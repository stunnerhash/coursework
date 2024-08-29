#include<stdio.h>
#include<math.h>
#include<limits.h>

int main(){
  int n, m;
  printf("Enter size of array in (n,m):\n");
  scanf("%d%d", &n, &m);
  printf("Enter array elements:\n");
  int a[n][m];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m;j++)
      scanf("%d", &a[i][j]); 

  int ans[m][n];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m;j++)
      ans[j][i] = a[i][j];

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n;j++){
      printf("%d " , ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}  

