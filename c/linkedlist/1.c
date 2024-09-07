#include "linkedlist.h"

int main() {
	struct node *head = NULL;

  head = append(head, 1);
  print_list(head);

	for (int i = 1; i < 9; i++) {
		head = insert(head, i*10, i);
		print_list(head);
	}

  head = append(head, 99);
  print_list(head);

	return 0;
}
