#include<stdio.h>
#include<math.h>
#include<limits.h>

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
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

