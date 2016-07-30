#include <iostream>
#include "linked_list.h"

int return_k_last(struct node **head, int k) {
	struct node *p1, *p2;
	int i;

	if (! *head)
		return -1;

	p1 = p2 = *head;
	i = 0;
	while (p2 && i <= k) {
		p2 = p2->next;
		i++;
	}
	if (!p2 && i!=k) { /*Exceed length*/
//		cout<<"i : "<<i<<" k : "<<k<<"\n";
		return -1;
	}
	if (!p2 && i==k) { /*equals length(first element)*/	
		return (*head)->val;
	}
	while (p2->next) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return (p1->next)->val;
}


int main() {
	struct node *head = NULL;
	int k;

	insert_node_back(&head, 1);
	insert_node_back(&head, 2);
	insert_node_back(&head, 3);
	insert_node_back(&head, 4);
	insert_node_back(&head, 5);
	k = 5;
	print_list(head);
	cout<<k<<"th element from last is : "<<return_k_last(&head, k)<<"\n";
return 0;
}
