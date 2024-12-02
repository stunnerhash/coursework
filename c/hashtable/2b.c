#include <stdio.h>
#include <stdlib.h>

struct node {
  char key;
  int val; // unused
  struct node* next;
};

struct node* table[26]; // create hash table

void insert(char key) 
{
  int idx = key - 'a';
  struct node* curr = table[idx];
  while (curr) {
    if (curr->key == key) return;  
    curr = curr->next;
  }

  // insert new node in front 
  struct node* newNode = (struct node*) malloc(sizeof(struct node));
  newNode->key = key;
  newNode->next = table[idx];
  table[idx] = newNode;
}

void solve()
{
  char str[1000]; 
  scanf("%s", &str);

  for(int i = 0; i < 26; i++) table[i] = NULL;  

  for (int i = 0; str[i]; i++) insert(str[i]);

  printf("Unique characters in '%s': ", str);
  for (int i = 0; i < 26; i++) {
    struct node* curr = table[i];
    while (curr) {
      printf("%c ", curr->key);
      curr = curr->next;
    }
  }
  printf("\n");

}

int main()
{
  int t; 
  scanf("%d", &t);
  while(t--) solve();
}
