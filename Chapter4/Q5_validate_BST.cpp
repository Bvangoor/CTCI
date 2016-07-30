#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
        int val;
        struct node *left;
        struct node *right;
};

struct node *allocate_node(int val) {
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->val = val;
        temp->left = temp->right = NULL;
        return temp;
}

bool validate_BST(struct node *root, int min, int max) {
	if (!root)
		return true;
	bool left, right;
	left = validate_BST(root->left, min, root->val);
	right = validate_BST(root->right, root->val, max);
	if (left && right) {
		if (root->val > min && root->val < max)
			return true;
	}
	return false;
}

int main() {
        struct node *node1, *node2, *node3, *node4, *node5, *node6, *node7;
        node1 = allocate_node(10);
        node2 = allocate_node(5);
        node3 = allocate_node(15);
	node4 = allocate_node(21);
        node5 = allocate_node(8);
        node6 = allocate_node(12);
	node7 = allocate_node(18);

        node1->left = node2;
        node1->right = node3;
        node2->left = node4;
        node2->right = node5;
	node3->left = node6;
	node3->right = node7;

	cout<<"The BST is valid or not : "<<validate_BST(node1, INT_MIN, INT_MAX)<<"\n";
return 0;
}
