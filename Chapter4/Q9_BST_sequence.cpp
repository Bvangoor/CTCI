#include <iostream>
#include <vector>
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

void print_lists(vector<vector<int> > list) {
	vector<int> temp;
	int size;

	size = list.size();
	for (int i = 0; i < size; i++) {
		temp = list[i];
		for (int j=0; j<temp.size(); j++)
			cout<<temp[j]<<" ";
		cout<<"\n";
	}
}

void print_list(vector<int> list) {

	for (int j=0; j < list.size(); j++)
		cout<<list[j]<<" ";
	cout<<"\n";
}

void copy_list(vector<int>& dest, vector<int> src) {
	for (int i=0; i < src.size(); i++)
		dest.push_back(src[i]);
}

vector<vector<int> > BST_sequence(struct node *root) {
	vector<vector<int> > result;
	vector<vector<int> > temp1;
	vector<vector<int> > temp2;
	int temp;

	if (!root)
		return result;
	temp = root->val;
	if (root->left)
		temp1 = BST_sequence(root->left);
	if (root->right)
		temp2 = BST_sequence(root->right);
	if (!root->left && !root->right) {
		vector<int> temp3;
		temp3.push_back(temp);
		result.push_back(temp3);
		return result;
	}
//	print_lists(temp1);
//	print_lists(temp2);
	for (int i=0; i < temp1.size(); i++) {
		vector<int> temp3;
		temp3.push_back(temp);
		copy_list(temp3, temp1[i]);
		for (int j=0; j < temp2.size(); j++) {
			vector<int> temp4;
			copy_list(temp4, temp3);
			copy_list(temp4, temp2[j]);
			result.push_back(temp4);
		}
		if (temp2.size() == 0)
			result.push_back(temp3);
	}
	for (int i=0; i < temp2.size(); i++) {
                vector<int> temp3;
                temp3.push_back(temp);
                copy_list(temp3, temp2[i]);
                for (int j=0; j < temp1.size(); j++) {
                        vector<int> temp4;
                        copy_list(temp4, temp3);
                        copy_list(temp4, temp1[j]);
                	result.push_back(temp4);
                }
		if (temp1.size() == 0)
			result.push_back(temp3);
        }
//	print_lists(result);
	return result;
}

int main() {
	struct node *node1, *node2, *node3, *node4, *node5, *node6, *node7;
	vector<vector<int> > result;
        /*Allocate Nodes*/
        node1 = allocate_node(10);
      	node2 = allocate_node(5);
        node3 = allocate_node(15);
        node4 = allocate_node(3);
        node5 = allocate_node(8);
        node6 = allocate_node(12);
        node7 = allocate_node(17);
	/*BST Tree*/
	node1->left = node2;
        node1->right = node3;
        node2->left = node4;
        node2->right = node5;
        node3->left = node6;
        node3->right = node7;
	cout<<"Tree : \n";
	BFS(node1);
	result = BST_sequence(node1);
	cout<<"BST Sequence : \n";
	print_lists(result);
return 0;
}
