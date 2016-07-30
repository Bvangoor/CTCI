#include "linked_list.h"
#include<iostream>

using namespace std;

struct node *intersection(struct node *head1, struct node *head2) {
	int len1, len2, diff, i = 1;

	len1 = list_length(head1);
	len2 = list_length(head2);

	if (len1 < len2) {
		diff = len2 - len1;
		while (i <= diff) {
			head2 = head2->next;
			i++;
		}
	} else {
		diff = len1 - len2;
                while (i <= diff) {
                        head1 = head1->next;
                        i++;
                }
	}

	while (head1 && head2) {
		if (head1 == head2)
			return head1;
		head1 = head1->next;
		head2 = head2->next;
	}
	return NULL;
}

int main() {
	struct node *head1 = NULL, *head2 = NULL, *inter;

	insert_node_back(&head1, 1);
	insert_node_back(&head1, 2);
	insert_node_back(&head1, 3);
	insert_node_back(&head1, 4);

	insert_node_back(&head2, 5);
//	head2->next = head1->next->next;
	
	print_list(head1);
	print_list(head2);

	inter = intersection(head1, head2);
	if (inter)
		cout<<"Intersection at : "<<inter->val<<"\n";
	else
		cout<<"No Intersection\n";
return 0;
}
