#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <unistd.h>
using namespace std;

struct node {
	int val;
	struct node *left;
	int left_cnt;
	struct node *right;
	int right_cnt;
};

struct node *allocate_node(int val) {
	struct node *temp;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->val = val;
	temp->left = NULL;
	temp->left_cnt = 0;
	temp->right = NULL;
	temp->right_cnt = 0;
	return temp;
}

struct node *helper_func(struct node *root, int rnd_num) {
	if (root->left_cnt+1 == rnd_num)
		return root;
	else if (rnd_num <= root->left_cnt)
		return helper_func(root->left, rnd_num);
	else
		return helper_func(root->right, rnd_num-(root->left_cnt+1));
}

struct node *random_node(struct node *root) {
	int total_cnt, rndm_num;

	if (!root)
		return NULL;

	total_cnt = root->left_cnt + root->right_cnt + 1;
	rndm_num = (rand() % total_cnt) + 1;
	cout<<"Random generated : "<<rndm_num<<"\n";
	return helper_func(root, rndm_num);
}

struct node *insert_BST(struct node *root, int val) {
	struct node *temp, *curr, *temp1;

	temp = allocate_node(val);
	if (!root)
		return temp;
	temp1 = root;
	while (temp1) {
		curr = temp1;
		if (val == temp1->val)
			return root;
		else if (val < temp1->val) {
			temp1->left_cnt++;
			temp1 = temp1->left;
		} else {
			temp1->right_cnt++;
			temp1 = temp1->right;
		}
	}
	if (val < curr->val)
		curr->left = temp;
	else
		curr->right = temp;
	return root;
}

void print_inorder(struct node *root) {
	if (!root)
		return ;
	print_inorder(root->left);
	cout<<root->val<<"("<<root->left_cnt<<", "<<root->right_cnt<<")"<<" ";
	print_inorder(root->right);
}

int main() {
	struct node *node1 = NULL;

	node1 = insert_BST(node1, 15);
	node1 = insert_BST(node1, 5);
	node1 = insert_BST(node1, 20);
	node1 = insert_BST(node1, 3);
	node1 = insert_BST(node1, 10);
	node1 = insert_BST(node1, 17);
	node1 = insert_BST(node1, 22);

	print_inorder(node1);
	cout<<"\n";
	srand (time(NULL));
	for (int i=1;i<=7;i++)
		cout<<"Random Node : "<<random_node(node1)->val<<"\n";
return 0;
}
