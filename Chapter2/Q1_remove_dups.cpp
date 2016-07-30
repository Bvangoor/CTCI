#include <iostream>
#include <stdlib.h>
#include "linked_list.h"
#include <unordered_map>

using namespace std;

/*
struct node {
	int val;
	node *next;
};
*/
void remove_dups(struct node **head) {
	struct node *prev, *curr, *temp;
	unordered_map<int, int> Map;

	if (! *head)
		return ;

	prev = *head;
	curr = prev->next;
	Map[prev->val] = 1;
	while (curr) {
		if (Map.count(curr->val)) {
			temp = curr;
			prev->next = curr->next;
			curr = curr->next;
			free(temp);
		} else {
			Map[curr->val] = 1;
			prev=curr;
			curr = curr->next;	
		}
	}
}

void remove_dups_naive(struct node **head) {
	struct node *helper, *prev, *curr, *temp;

	if (! *head)
		return ;

	helper = *head;
	while (helper) {
		prev = helper;
		curr = prev->next;
		while (curr) {
			if (curr->val == helper->val) {
				temp = curr;
				prev->next = curr->next;
				curr = curr->next;
				free(temp);
			} else {
				prev = curr;
				curr = curr->next;
			}
		}
		helper = helper->next;
	}
}

/*
void insert_node_front(struct node **head, int num) {
	struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->val = num;
	temp->next = NULL;
	if (! *head) {
		*head = temp;
	} else {
		temp->next = *head;
		*head = temp;
	}
}

void insert_node_back(struct node **head, int num) {
	struct node *temp, *kemp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->val = num;
	temp->next = NULL;
	if (! *head) {
		temp->val = num;
		*head = temp;
		return ;
	}
	kemp = *head;
	while (kemp->next) {
		kemp=kemp->next;
	}
	kemp->next = temp;
}

void print_list(struct node *head) {
	struct node *temp;

	temp = head;
	while (temp) {
		cout<<temp->val<<"	";
		temp = temp->next;
	}
	cout<<"\n";
}

void free_list(struct node **head) {
	struct node *prev, *curr;
	
	if (! *head)
		return ;

	prev = *head;
	curr = prev->next;
	while (curr) {
		free(prev);
		prev = curr;
		curr = curr->next;
	}
}
*/
int main() {
	struct node *head=NULL;

	insert_node_back(&head, 1);
	insert_node_back(&head, 2);
	insert_node_back(&head, 3);
	insert_node_back(&head, 1);
	insert_node_back(&head, 2);
	insert_node_back(&head, 3);	
	print_list(head);
//	remove_dups(&head);
	remove_dups_naive(&head);
	print_list(head);
	free_list(&head);
}
