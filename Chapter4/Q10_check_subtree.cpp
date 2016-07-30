#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct node {
	int val;
	struct node *left;
	struct node *right;
};

string build_preorder_string(struct node *root) {
	string temp = "";
	if (root) {
		temp += to_string(root->val);
	} else {
		temp += "N";
		return temp;
	}
	temp += build_preorder_string(root->left);
	temp += build_preorder_string(root->right);
	return temp;
}

bool check_subtree(struct node *T1, struct node *T2) {
	string one, two;
	one = build_preorder_string(T1);
	two = build_preorder_string(T2);
	if (one.find(two) != string::npos)
		return true;
	return false;
}

struct node *allocate_node(int val) {
	struct node *temp;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int main() {
	struct node *node1, *node2, *node3, *node4, *temp;
	node1 = allocate_node(1);
	node2 = allocate_node(2);
	node3 = allocate_node(3);
	node4 = allocate_node(4);
	temp = allocate_node(6);

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	
	cout<<"Check Subtree : "<<check_subtree(node1, temp)<<"\n";
return 0;
}
