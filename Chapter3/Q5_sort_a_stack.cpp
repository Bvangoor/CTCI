#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	int val;
	struct node *next;
};

void push(struct node **head, int val) {
	struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->val = val;
	temp->next = NULL;

	if (!*head)
		*head = temp;
	else {
		temp->next = *head;
		*head = temp;
	}
}

void pop(struct node **head) {
	struct node *temp;
	if (!*head) {
		cout<<"Pop Error : Stack Empty\n";
		return ;
	}

	temp = *head;
	*head = (*head)->next;
	free(temp);
}

int top(struct node **head) {
	if (!*head) {
		cout<<"Top Error : Stack Empty\n";
		return -1;
	}
	return (*head)->val;
}

void print_stack(struct node *head) {
	struct node *temp;

	temp = head;
	while (temp) {
		cout<<temp->val<<"\n";
		temp = temp->next;
	}
	cout<<"\n";
}

struct node *sort_stack(struct node **head) {
	struct node *temp = NULL, *stack;
	int val;

	stack = *head;
	while (stack) {
		val = top(&stack);
		pop(&stack);
//		cout<<"VAL : "<<val<<"\n";
		while (temp) {
			if (val > top(&temp))
				break;
			else {
				push(&stack, top(&temp));
				pop(&temp);
			}
		}
//		cout<<"Pushing "<<val<<" to temp\n";
		push(&temp, val);
	}
	while (temp) {
		push(&stack, top(&temp));
		pop(&temp);
	}
	return stack;
}

int main() {
	struct node *stack = NULL;
	push(&stack, 12);
	push(&stack, 8);
	push(&stack, 24);
	push(&stack, 1);
	print_stack(stack);
	stack = sort_stack(&stack);
	print_stack(stack);
return 0;
}
