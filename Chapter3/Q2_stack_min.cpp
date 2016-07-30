#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

struct node {
	int val;
	int min;
	struct node *next;
}*head = NULL;

void push(int val) {
	struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->val = val;
	temp->next = NULL;
	if (!head) {
		temp->min = val;
		head = temp;
	} else {
		temp->min = min(val, head->min);
		temp->next = head;
		head = temp;
	}
}

void pop(){
	struct node *temp;

	if (!head) {
		cout<<"Stack is empty\n";
	} else {
		temp = head;
		head = head->next;
		free(temp);
	}
}

void getmin() {
	if (!head)
		cout<<"Stack is empty\n";
	else
		cout<<"Min Value is "<<head->min<<"\n";
}

int main() {
	push(3);
	push(2);
	getmin();
	pop();
	getmin();	
	push(1);
	getmin();	
	push(5);
	getmin();
return 0;
}
