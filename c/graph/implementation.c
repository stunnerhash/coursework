#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct node {
  int data;
  struct node* next;
};

struct node* createNode(int data);

void addEdge(struct node* adj[], int u, int v);

void displayAdjList(struct node* adj[], int v);

void dfs(struct node* adj[], bool vis[], int v, int root, int len);

void bfs(struct node* adj[], bool vis[], int v, int root);

int main()
{
  int v = 4;

  struct node* adj[v];

  bool vis[v];
  for(int i =0 ;i<v;i++) {
    adj[i] = NULL;
  }
    
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  
  memset(vis,false,sizeof(vis));
  dfs(adj, vis, v, 0, 0);

  printf("\n");
  memset(vis,false,sizeof(vis));
  bfs(adj,vis,v,0);
}

void dfs(struct node* adj[], bool vis[], int v, int root, int len)
{
  if(vis[root]) {
    return;
  }      

  vis[root] = true;

  printf("%d-%d ", len, root);

  struct node* temp = adj[root];

  while(temp) 
  {
    dfs(adj,vis,v,temp->data, len+1);
    temp = temp->next;
  }
}

void bfs(struct node* adj[], bool vis[], int v, int root)
{
  int head = 0, tail = 0;
  int queue[1000];
  int len[1000];
  
  len[tail] = 0; 
  queue[tail++] = root;
  vis[root] = true;  

  while(head<tail)
  {
    int l = len[head];
    int x = queue[head++];
    
    printf("%d-%d ", l, x);

    struct node* temp = adj[x];
    while(temp) 
    {
      if(!vis[temp->data]) 
      {
        vis[temp->data] = true;
        len[tail] = l+1;
        queue[tail++] = temp->data;
      } 
      temp=temp->next;
    }
  }
  printf("\n");
}

struct node* createNode(int data)
{
  struct node* newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void addEdge(struct node* adj[], int u, int v)
{
  struct node* newNode = createNode(v);
  newNode->next = adj[u];
  adj[u] = newNode;

  newNode = createNode(u);
  newNode->next = adj[v];
  adj[v] = newNode;
}

void displayAdjList(struct node* adj[], int v) 
{
    for (int i = 0; i < v; i++) {
        printf("%d: ", i); 
        struct node* temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->data); 
            temp = temp->next;
        }
        printf("\n");
    }
}
