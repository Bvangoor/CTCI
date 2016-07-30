#include "linked_list.h"
#include <iostream>

void partition(struct node **head, int val) {
	struct node *temp1, *temp, *highest = NULL;
	int kemp;

	temp = *head;
	while (temp) {
		if (temp->val >= val) {
			if (highest == NULL)
				highest = temp;
		} else if (highest) {
				kemp = temp->val;
				temp->val = highest->val;
				highest->val = kemp;
				highest = highest->next;
		}
		temp = temp->next;
	}
}

int main() {
	struct node *head = NULL;

	insert_node_back(&head, 3);
	insert_node_back(&head, 5);
	insert_node_back(&head, 8);
	insert_node_back(&head, 5);
	insert_node_back(&head, 10);
	insert_node_back(&head, 2);
	insert_node_back(&head, 1);

	print_list(head);
	partition(&head, 5);
	print_list(head);

return 0;
}
