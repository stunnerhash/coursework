#ifndef LINKEDLIST_H_   
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

/*
 * linkedlist.h - A simple implementation of a singly linked list
 *
 * This header file defines the structure of a singly linked list node
 * and declares functions for inserting, appending, and printing the list.
 */

/* 
 * Struct: node
 * Represents a node in the linked list.
 * Fields:
 *   - val: an integer value stored in the node.
 *   - next: a pointer to the next node in the linked list.
 */
struct node {
	int val;
	struct node *next;
};

/* 
 * Function: insert
 * Inserts a node at the specified position in the linked list.
 * Parameters:
 *   - head: the head of the linked list.
 *   - value: the value to be inserted.
 *   - position: the position (0-based index) at which to insert the new node.
 * Returns:
 *   - The updated head of the linked list.
 */
struct node* insert(struct node *head, int value, int position);

/* 
 * Function: append
 * Appends a new node with the specified value to the end of the linked list.
 * Parameters:
 *   - head: the head of the linked list.
 *   - value: the value to append to the list.
 * Returns:
 *   - The updated head of the linked list.
 */
struct node* append(struct node *head, int value);

/*
 * Function: delete
 * Delete a node with specified position in the linked list
 * Parameters:
 *   - head: the head of the linked list.
 *   - position: the position (0-based index) to be deleted
 * Returns:
 *   - The updated head of the linked list.
 */
struct node* delete(struct node* head, int position);

/* 
 * Function: print_list
 * Prints the values in the linked list from head to the last node.
 * If the list is empty, prints "(empty)".
 * Parameters:
 *   - head: the head of the linked list.
 */
void print_list(struct node *head);

#endif  
