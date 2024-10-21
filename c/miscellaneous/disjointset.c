#include <stdio.h>
#include <stdlib.h>

int *parent;

void createSet(int n) {
    parent =(int *)malloc(n*sizeof(int));
    for (int i=0; i<n; i++) {
        parent[i]=i; 
    }
}

int find(int x) {
    if (parent[x]!=x) {
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX =find(x);
    int rootY =find(y);
    parent[rootY]=rootX; 
    
}

void printSet(int n) {
    printf("Element:");
    for (int i=0;i<n;i++) {
        printf("%d ",i);
    }
    printf("\nParent:");
    for (int i=0;i<n;i++) {
        printf("%d ",parent[i]);
    }
    printf("\n");
}

int main() {

    int n;
    scanf("%d",&n);
    createSet(n);

    int arr[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                unionSets(i,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(parent[i]==i)
            printf("%d ",i+1);
    }


    free(parent);

    return 0;
}
