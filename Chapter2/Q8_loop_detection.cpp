#include "linked_list.h"
#include <iostream>

using namespace std;

struct node *detect_loop(struct node *head) {
	struct node *p1, *p2;

	p1 = p2 = head;
	while (p1 && p2) {
		p2 = p2->next;
		if (p2)
			p2 = p2->next;
		else {
			return NULL;
		}
		p1 = p1->next;
		if (p1 == p2) {
			p1 = head;
			break;
		}
	}
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

int main() {
	struct node *head = NULL, *detect = NULL;

	insert_node_back(&head, 1);
	insert_node_back(&head, 2);
	insert_node_back(&head, 3);
	insert_node_back(&head, 4);
	insert_node_back(&head, 5);

//	head->next->next->next->next->next = head; /*5->3*/
	detect = detect_loop(head);
	if (detect)
		cout<<"Loop at : "<<detect->val<<"\n";
	else
		cout<<"No Loop\n";
return 0;
}
