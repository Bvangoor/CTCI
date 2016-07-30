#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct node {
	int val;
	node *left;
	node *right;
	node *next;
};

struct node *allocate_node(int val) {
	struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	temp->next = NULL;
	return temp;
}

void depth_lists(struct node **node) {
	deque<struct node*> Queue;
	struct node *temp, *temp1, *root;
	
	root = *node;
	Queue.push_back(root);
	while (Queue.size() > 0) {
		int size;
		temp = Queue[0];
		Queue.pop_front();
		size = Queue.size();
		if (temp->left)
			Queue.push_back(temp->left);
		if (temp->right)
			Queue.push_back(temp->right);
		while (size) {
			temp1 = Queue[0];
			Queue.pop_front();
			size--;
			temp->next = temp1;
			temp = temp1;
			if (temp->left)
				Queue.push_back(temp->left);
			if (temp->right)
				Queue.push_back(temp->right);
		}
	}
}

void print_depth_lists(struct node *root) {
	struct node *temp, *temp1;

	temp = root;
	while (temp) {
		temp1 = temp;
		while (temp1) {
			cout<<temp1->val<<"->";
			temp1 = temp1->next;
		}
		cout<<"NULL\n";
		temp= temp->left;
	}
}

int main() {
	struct node *node1, *node2, *node3, *node4, *node5, *node6, *node7;

	node1 = allocate_node(1);
	node2 = allocate_node(2);
	node3 = allocate_node(3);
	node4 = allocate_node(4);
	node5 = allocate_node(5);
	node6 = allocate_node(6);
	node7 = allocate_node(7);

	node1->left = node2;
	node1->right = node3;	
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	node3->right = node7;
	
	depth_lists(&node1);
	print_depth_lists(node1);
return 0;
}
