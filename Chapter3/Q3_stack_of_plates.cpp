#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
using namespace std;

struct node {
	int val;
	struct node *next;
};

vector<struct node *> setOfStacks;
double threshold; /*size of each stack*/
double size; /*Total Size*/
int counter; /*count of vector*/
int available; /*available space*/

void initialise(int thrshld) {
	threshold = thrshld;
	size = 0;
	counter = 0;
	available = 0;
}

void push(int val) {
	struct node *temp_head = NULL;
	if (available == 0) {
		counter++;
		temp_head = (struct node *)malloc(sizeof(struct node));
		temp_head->val = val;
		temp_head->next = NULL;
		setOfStacks.push_back(temp_head);
		available = threshold-1;
		size++;
	} else {
		temp_head = setOfStacks[counter-1];
		struct node *temp;
		temp = (struct node *)malloc(sizeof(struct node));
		temp->val = val;
		temp->next = temp_head;
		available -= 1;
		size++;
		setOfStacks[counter-1] = temp;
	}
}

void pop() {
	struct node *temp_head, *temp;
	if (size > 0) {
		counter = ceil(size/threshold);
		cout<<"counter : "<<counter<<"\n";
		temp_head = setOfStacks[counter-1];
		temp = temp_head;
		temp_head = temp_head->next;
		setOfStacks[counter-1] = temp_head;
		size--;
		available++;
		counter = ceil(size/threshold);
		free(temp);
	} else {
		cout<<"Stack is Empty\n";
	}
}

void peek() {
	struct node *temp_head;
	if (size > 0) {
		temp_head = setOfStacks[counter-1];
		cout<<"Top Value is : "<<temp_head->val<<"\n";
	} else {
		cout<<"Stack is empty\n";
	}
}

int main() {
	initialise(3);
	push(1);
	push(2);
	push(3);
//	peek();
	push(4);
	push(5);
	push(6);
	peek();
	pop();
	peek();
	pop();
	peek();
	pop();
	peek();
}
