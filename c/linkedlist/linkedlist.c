#include <stdlib.h>
#include "linkedlist.h"

/* 
 * Function: print_list
 * Prints the values in the linked list from head to the last node.
 */
void print_list(struct node *head)
{
  struct node *temp = NULL;
  
  if (head == NULL) {
		printf("(empty)\n");
		return;
	}

	for (temp = head; temp != NULL; temp = temp->next) {
		printf("%d -> ", temp->val);
	}

	printf("(NULL)\n");
}

/* 
 * Function: insert
 * Inserts a new node with the given value at the specified position.
 */
struct node* insert(struct node *head, int value, int position) 
{
	struct node *temp = NULL;
	struct node *new_node = NULL;

	new_node = (struct node *) malloc(sizeof(struct node));
	new_node->val = value;
	new_node->next = NULL;

	if (position == 0) {
		new_node->next = head;
		return new_node;
	}

  temp = head;
  for (
    int i = 0;
    temp != NULL && i < position - 1 ; 
    temp = temp->next, ++i
  );

	if (temp == NULL) {
		printf("Position greater than size of linked list\n");
    free(new_node);
		return head;
	}

	new_node->next = temp->next;
	temp->next = new_node;

	return head;
}

/* 
 * Function: append
 * Appends a new node with the given value at the end of the list.
 */
struct node* append(struct node *head, int value) 
{
	struct node *tail = NULL;
	struct node *new_node = NULL;

	new_node = (struct node *) malloc(sizeof(struct node));
	new_node->val = value;
	new_node->next = NULL;

	if (head == NULL) {
    free(new_node);
		return new_node;
	}

	for (tail = head; tail->next != NULL; tail = tail->next);

	tail->next = new_node;

	return head;
}

/* 
 * Function: Delete
 * Delete a with given position from linked list;
 */
struct node* delete(struct node* head, int position)
{
  // struct node* temp = NULL;
  // struct node* ahead = NULL;

  // if(head == NULL){
  //   return head;
  // }

  // temp = head;
  // ahead = head->next;

  // if(position == 0){
  //   free(temp);
  //   return ahead;
  // }

  // for( int i = 0; ahead != NULL && i < position - 1; i++){
  //   temp = ahead;
  //   ahead = ahead->next; 
  // };

  // if(ahead == NULL){
  //   printf("position is greater than size of linked list\n");
  //   return head; 
  // }

  // temp = ahead->next;
  // free(ahead);

  // return head;
}

