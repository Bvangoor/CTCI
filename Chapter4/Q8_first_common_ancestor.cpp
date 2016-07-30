#include <iostream>
#include <stdlib.h>
#include <deque>
using namespace std;

struct node {
	int val;
	struct node *left;
	struct node *right;
};

struct node *allocate_node(int val) {
	struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void BFS(struct node *root) {
	deque<struct node *> queue;
	struct node *temp;
	int size;

	if (!root)
		return ;
	queue.push_back(root);
	while (queue.size() > 0) {
		size = queue.size();
		while (size > 0) {
			temp = queue[0];
			queue.pop_front();
			cout<<temp->val<<" ";
			if (temp->left)
				queue.push_back(temp->left);
			if (temp->right)
				queue.push_back(temp->right);
			size--;
		}
		cout<<"\n";
	}
}

bool check_in_tree(struct node *root, struct node *node) {
	if (!root || !node)
		return false;
	if (root == node)
		return true;
	return (check_in_tree(root->left, node) || check_in_tree(root->right, node));
}

struct node *First_Common_Ancestor_Helper(struct node *root, struct node *node1, struct node *node2) {
	struct node *left, *right;

	if (!root)
		return NULL;	

	if (root == node1 || root == node2)
		return root;

	left = right = NULL;
	left = First_Common_Ancestor_Helper(root->left, node1, node2);
	right = First_Common_Ancestor_Helper(root->right, node1, node2);
	if (left && right)
		return root;

	return (left ? left : right);
}

struct node *First_Common_Ancestor(struct node *root, struct node *node1, struct node *node2) {
	bool left, right;

	left = check_in_tree(root, node1);
	right = check_in_tree(root, node2);
//	cout<<"Good so far : "<<left<<" "<<right<<"\n";
	if (left && right)
		return First_Common_Ancestor_Helper(root, node1, node2);
	else
		return NULL;
}

int main() {
	struct node *node1, *node2, *node3, *node4, *node5, *node6, *node7, *node8, *node9, *node10;
	struct node *temp = NULL;
	/*Allocate Nodes*/
	node1 = allocate_node(1);
	node2 = allocate_node(2);
	node3 = allocate_node(3);
	node4 = allocate_node(4);
	node5 = allocate_node(5);
	node6 = allocate_node(6);
	node7 = allocate_node(7);
	node8 = allocate_node(8);
	node9 = allocate_node(9);
	node10 = allocate_node(10);
	/*Tree*/
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node3->right = node5;
	node4->left = node6;
	node4->right = node7;
	node5->left = node8;
	node5->right = node9;
	cout<<"Tree : \n";
	BFS(node1);
	temp = First_Common_Ancestor(node1, node8, node10);
	cout<<"Common Ancestor of : "<<node8->val<<" and "<<node10->val<<" is : "<<( temp ? temp->val : NULL)<<"\n";
return 0;
}
