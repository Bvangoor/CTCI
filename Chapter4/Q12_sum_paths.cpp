#include <iostream>
#include <deque>
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

void root_sum(struct node *root, int *count, int sum) {
	if (!root)
		return ;
	if (root->val == sum) {
		(*count)++;
		return ;
	}
	root_sum(root->left, count, sum - (root->val));
	root_sum(root->right, count, sum - (root->val));
}

void path_sum(struct node *root, int *count, int sum) {
	if (!root)
		return ;
	root_sum(root, count, sum);
	if (root->left)
		path_sum(root->left, count, sum);
	if (root->right)
		path_sum(root->right, count, sum);
}

int main() {
	struct node *node1, *node2, *node3, *node4, *node5, *node6, *node7;
	int counter = 0, sum = 11;

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

	cout<<"Tree : \n";
	BFS(node1);
	path_sum(node1, &counter, sum);
	cout<<"No. of paths with sum : "<<sum<<" is : "<<counter<<"\n";
return 0;
}
