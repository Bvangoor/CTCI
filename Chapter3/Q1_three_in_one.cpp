#include <iostream>
#include <stdlib.h>

using namespace std;

int *multiArray;
int *sizes;
int *indexes;
int stackCapacity;
int stackNum;

void initilise(int stackcapacity, int stacknum) {
	stackCapacity = stackcapacity;
	stackNum = stacknum;
	multiArray = (int *)malloc(stackCapacity*stackNum*sizeof(int));
	sizes = (int *)malloc(stackNum*sizeof(int));
	memset(sizes, 0, sizeof(&sizes));
	indexes = (int *)malloc(stackNum*sizeof(int));
	for (int i=0; i < stacknum; i++) {
		indexes[i] = stackcapacity*i;
	}
}

void destroy() {
	free(multiArray);
	free(sizes);
	free(indexes);
}

void push(int stacknum, int val) {
	if (stacknum >= stackNum) {
		cout<<"Stack Number Not defined\n";
		return ;
	}
	if (sizes[stacknum] == stackCapacity) {
		cout<<"Stack is Full\n";
		return ;
	}
	multiArray[indexes[stacknum]] = val;
	indexes[stacknum]++;
	sizes[stacknum]++;
}

void pop(int stacknum) {
	if (stacknum >= stackNum) {
                cout<<"Stack Number Not defined\n";
                return ;
        }
	if (sizes[stacknum] == 0) {
		cout<<"Stack is Empty\n";
		return ;
	}
	sizes[stacknum]--;
	indexes[stacknum]--;
}

int peek(int stacknum) {
	if (stacknum >= stackNum) {
                cout<<"Stack Number Not defined\n";
                return -1;
        }
        if (sizes[stacknum] == 0) {
                cout<<"Stack is Empty\n";
                return -1;
        }
	return multiArray[indexes[stacknum]-1];
}

void isempty(int stacknum) {
	if (stacknum >= stackNum) {
                cout<<"Stack Number Not defined\n";
                return ;
        }
	if (sizes[stacknum] == 0)
                cout<<"Stack is Empty\n";
        else
		cout<<"Stack is Not Empty\n";
}

int main() {
	initilise(3, 3); /*Stack nums start from 0*/
	push(0, 1);
	push(0, 2);
	push(0, 4);
	push(0, 5);
	push(1, 11);
	push(1, 12);
	push(1, 14);
	push(1, 15);
	cout<<"top of stack 1 : "<<peek(0)<<"\n";
	cout<<"top of stack 2 : "<<peek(1)<<"\n";
	cout<<"top of stack 3 : "<<peek(2)<<"\n";	
	pop(0);
	pop(1);
	pop(0);
	pop(1);
	pop(0);
	pop(1);
	pop(0);
	pop(1);
	isempty(0);
	isempty(1);
	destroy();
}
