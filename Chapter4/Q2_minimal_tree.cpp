#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct node {
	int val;
	struct node *left;
	struct node *right;
};

struct node *minimal_tree(vector<int>& array, int low, int high) {
	struct node *temp;
	int mid;

	if (low <= high) {
		mid = low + (high-low)/2;
		temp = (struct node*)malloc(sizeof(struct node));
		temp->val = array[mid];
		temp->left = minimal_tree(array, low, mid-1);
		temp->right = minimal_tree(array, mid+1, high);
		return temp;
	} else
		return NULL;
}

void print_inorder(struct node *root) {
	if (root) {
		print_inorder(root->left);
		cout<<root->val<<"\n";
		print_inorder(root->right);
	}
}

int main() {
	vector<int> Array;
	struct node *root;

	Array.push_back(1);
	Array.push_back(2);
	Array.push_back(3);
	Array.push_back(4);
	Array.push_back(5);
	root = minimal_tree(Array, 0, Array.size()-1);
	print_inorder(root);
return 0;
}
