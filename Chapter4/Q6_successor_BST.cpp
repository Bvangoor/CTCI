#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
        int val;
        struct node *left;
        struct node *right;
	struct node *parent;
};

struct node *allocate_node(int val) {
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->val = val;
        temp->left = temp->right = temp->parent = NULL;
        return temp;
}

struct node *BST_successor(struct node *node) {
	struct node *temp;
	if (node->right) {
		temp = node->right;
		while (temp->left)
			temp = temp->left;
		return temp;
	}
	temp = node->parent;
	while (temp) {
		if (temp->val > node->val)
			return temp;
		temp = temp->parent;
	}
	return NULL;
}

int main() {
	struct node *node1, *node2, *node3, *node4, *node5, *node6, *node7, *temp;
        node1 = allocate_node(10);
        node2 = allocate_node(5);
        node3 = allocate_node(18);
        node4 = allocate_node(2);
        node5 = allocate_node(8);
        node6 = allocate_node(16);
        node7 = allocate_node(21);

        node1->left = node2;
	node2->parent = node1;
        node1->right = node3;
	node3->parent = node1;
        node2->left = node4;
	node4->parent = node2;
        node2->right = node5;
	node5->parent = node2;
        node3->left = node6;
	node6->parent = node3;
        node3->right = node7;
	node7->parent = node3;
	temp = BST_successor(node5);
	cout<<"The next node (in order) of "<<node5->val<<" is : "<<((temp) ? temp->val : NULL)<<"\n";
return 0;
}
