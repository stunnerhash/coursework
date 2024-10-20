#include<stdio.h>

#define N 1000
int par[N];

void init() {
  for(int i = 0;i<N;i++) par[i] = i;
}
int find_set(int x) {
  if(par[x] == x) return x;
  return par[x] = find_set(par[x]);
}
void union_set(int u, int v) {
  int x = find_set(u);
  int y = find_set(v);
  par[y] = x;
}

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      int in; 
      scanf("%d", &in);
      if(in) union_set(i,j);
    }
  } 

  int ans = 0;
  for(int i = 0;i<n;i++)  
    if(par[i] == i) ans ++;
  
  printf("%d\n", ans);
  for(int i = 0;i<n;i++) 
    if(par[i] == i) 
      printf("%d ", i+1);

  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--){
    init();
    solve();
  }
  return 0;
}
