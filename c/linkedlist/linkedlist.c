#include "linkedlist.h"

/* 
 * Function: print_list
 * Prints the values in the linked list from head to the last node.
 */
void print_list(struct node *head)
{
	if (head == NULL) {
		printf("(empty)\n");
		return;
	}
	for (struct node *tmp = head; tmp != NULL; tmp = tmp->next) {
		printf("%d -> ", tmp->val);
	}
	printf("(NULL)\n");
}

/* 
 * Function: insert
 * Inserts a new node with the given value at the specified position.
 */
struct node* insert(struct node *head, int value, int position) {
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
	for (int i = 0; i < position - 1; i++) {
		if (temp == NULL) {
			printf("Position greater than size of linked list\n");
			return head;
		}
		temp = temp->next;
	}
	
	if (temp == NULL) {
		printf("Position greater than size of linked list\n");
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
struct node* append(struct node *head, int value) {
	struct node *tail = NULL;
	struct node *new_node = NULL;

	new_node = (struct node *) malloc(sizeof(struct node));
	new_node->val = value;
	new_node->next = NULL;

	if (head == NULL) {
		return new_node;
	}

	for (tail = head; tail->next != NULL; tail = tail->next);

	tail->next = new_node;

	return head;
}
