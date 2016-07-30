#include <iostream>
#include <stdlib.h>
#include <cmath>
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

int get_height(struct node *temp) {
	if (!temp)
		return 0;
	return 1 + max(get_height(temp->left), get_height(temp->right));
}

bool check_balanced(struct node *root) {
	int left_height, right_height;
	bool left_isbalanced, right_isbalanced;
	
	if (!root)
		return true;
	left_isbalanced = right_isbalanced = false;
	left_isbalanced = check_balanced(root->left);
	right_isbalanced = check_balanced(root->right);
	if (left_isbalanced && right_isbalanced) {
		left_height = get_height(root->left);
		right_height = get_height(root->right);
		if (abs(left_height - right_height) <= 1)
			return true;
		else
			return false;
	} else
		return false;
}

int main() {
	struct node *node1, *node2, *node3, *node4, *node5, *node6, *node7;
	node1 = allocate_node(1);
	node2 = allocate_node(2);
	node3 = allocate_node(3);
//	node4 = allocate_node(4);
	node5 = allocate_node(2);
	node6 = allocate_node(3);
//	node7 = allocate_node(4);

	node1->left = node2;
	node1->right = node5;
	node2->left = node3;
	node5->right = node6;
//	node3->left = node4;
//	node6->right = node7;

	cout<<"Tree is Balanced or not : "<<check_balanced(node1)<<"\n";

return 0;
}
