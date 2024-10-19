#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int *rank;
  int *parent;
  int size;
}DisjointSet;

DisjointSet *createSet(int n){
  DisjointSet *ds =(DisjointSet*)malloc(sizeof(DisjointSet));
  ds->size=n;
  ds->rank=(int*)malloc(n*sizeof(int));
  ds->parent=(int*)malloc(n*sizeof(int));
  for(int i=0;i<n;i++){
    ds->parent[i]=i;
    ds->rank[i]=0;
  }
  return ds;
}

int findSet(DisjointSet *ds,int x){
  if(ds->parent[x]==x){
    return ds->parent[x];
  }
  return ds->parent[x]=findSet(ds,ds->parent[x]);
}

void unionset(DisjointSet *ds,int x,int y){
  int rootx=findSet(ds,x);
  int rooty=findSet(ds,y);
  if(ds->rank[rootx]>ds->rank[rooty]){
    ds->parent[rooty]=rootx;
  }
  else if(ds->rank[rooty]>ds->rank[rootx]){
    ds->parent[rootx]=rooty;
  }
  else {
    ds->parent[rooty]=rootx;
    ds->rank[rootx]++;
  }

}

void unionbyValue(DisjointSet *ds,int x,int y){
  int rootx=findSet(ds,x);
  int rooty=findSet(ds,y);

  if(rootx!=rooty){

    if(rootx>rooty){
      ds->parent[rooty]=rootx;

    }
    else{
      ds->parent[rootx]=rooty;
    }
  }
}

int main(){
  int n=10;
  DisjointSet *ds=createSet(n);

  unionbyValue(ds,1,5);
  unionbyValue(ds,3,7);
  unionbyValue(ds,1,4);
  unionbyValue(ds,5,7);
  unionbyValue(ds,0,8);
  unionbyValue(ds,6,9);
  unionbyValue(ds,3,9);

  for(int i=0;i<n;i++){
    printf("representative of %d is %d\n: ",i,findSet(ds,i));
  }
  return 0;
}
