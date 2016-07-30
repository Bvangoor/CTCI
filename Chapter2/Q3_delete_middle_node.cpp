#include "linked_list.h"
#include <iostream>

using namespace std;

void delete_mid_node(struct node **node) {
	struct node *temp, *kemp;
	
	temp = *node;
	kemp = temp->next;
	temp->val = kemp->val;
	temp->next = kemp->next;
	free(kemp);
}

int main() {
	struct node *head = NULL;

	insert_node_back(&head, 1);
	insert_node_back(&head, 2);
	insert_node_back(&head, 3);
	insert_node_back(&head, 4);
	insert_node_back(&head, 5);
	print_list(head);
	delete_mid_node(&(head->next));
	print_list(head);
return 0;
}
