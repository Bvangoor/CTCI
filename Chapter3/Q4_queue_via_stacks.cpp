#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
	int val;
	struct node *next;
};

struct node *head1 = NULL, *head2 = NULL;

void push(struct node **head, int val) {
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->val = val;
	temp->next = NULL;

	if (!*head) {
		*head = temp;
	} else {
		temp->next = *head;
		*head = temp;
	}
}

void enqueue(int val) {
	push(&head1, val);
}

int peek(struct node **head) {
	return (*head)->val;
}

void pop(struct node **head) {
	struct node *temp;

	temp = *head;
	*head = (*head)->next;
	free(temp);
}

void dequeue() {
	if (!head2) {
		if (head1) {
			while (head1) {
				push(&head2, peek(&head1));
				pop(&head1);
			}
			pop(&head2);
		} else {
			cout<<"Stack is Empty\n";
		}
	} else {
		pop(&head2);
	}
}

int top() {
	if (!head2) {
                if (head1) {
                        while (head1) {
                                push(&head2, peek(&head1));
                                pop(&head1);
                        }
			return head2->val;
                } else {
                        cout<<"Stack is Empty\n";
			return -1;
                }
        } else {
                return head2->val;
        }
}

bool isEmpty() {
	if (!head1 && !head2)
		return true;
	return false;
}

int main() {
	enqueue(1);
	enqueue(2);
	enqueue(3);
	cout<<"Top : "<<top()<<"\n";
	dequeue();
	cout<<"Top : "<<top()<<"\n";
	enqueue(4);
	dequeue();
	dequeue();
	cout<<"Top : "<<top()<<"\n";
return 0;
}
