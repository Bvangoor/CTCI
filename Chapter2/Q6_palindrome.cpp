#include "linked_list.h"
#include <iostream>


struct node *find_middle_node(struct node *head) {
	struct node *p1, *p2;

	p1 = p2 = head;
	while (p1 && p2) {
		p2 = p2->next;
		if (p2)
			p2 = p2->next;
		else
			break;
		p1 = p1->next;
	}
	return p1;
}

struct node *reverse_list(struct node *head) {
	struct node *curr, *next, *prev;

	prev = NULL;
	curr = head;
	while (curr->next) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	curr->next = prev;
	return curr;
}

void check_palindrome(struct node **head) {
	struct node *first, *middle, *last;
	int len, comp = 0, i = 1;

	first = *head;
	if (!first) {
		cout<<"TRUE\n";
		return ;
	}
	len = list_length(first);
	middle = find_middle_node(*head);
	last = reverse_list(middle);
	comp = len/2;
	while (first && last && i <= comp) {
		if (first->val != last->val) {
			cout<<"NOT TRUE\n";
			return ;
		}
		first = first->next;
		last = last->next;
		i++;
	}
	cout<<"TRUE\n";
}

int main() {
	struct node *head = NULL;

	insert_node_back(&head, 1);
	insert_node_back(&head, 2);
	insert_node_back(&head, 3);
	insert_node_back(&head, 2);
	insert_node_back(&head, 1);

	check_palindrome(&head);
	free_list(&head);
}
