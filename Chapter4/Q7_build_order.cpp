#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
using namespace std;

struct node {
	char projName;
	struct node **parents;
	int parents_cnt;
	struct node **children;
	int children_cnt;
};


unordered_map<char, int> Map;
vector<struct node*> Nodes;

struct node *allocate_node(char projname, int no_of_nodes) {
	struct node *temp;
	
	temp = (struct node*)malloc(sizeof(struct node));
	temp->projName = projname;
	temp->parents = (struct node**)malloc(no_of_nodes*sizeof(struct node*));
	temp->parents_cnt = 0;
	temp->children = (struct node**)malloc(no_of_nodes*sizeof(struct node*));
	temp->children_cnt = 0;
	return temp;
}

void print_tree() {
	int size;
	struct node *temp;

	size = Nodes.size();
	for (int i=0; i < size; i++) {
		temp = Nodes[i];
		cout<<"Proj Name : "<<temp->projName<<"\n";
		cout<<"Parents : ";
		for (int j=0; j < temp->parents_cnt; j++) {
			cout<<temp->parents[j]->projName<<", ";
		}
		cout<<"NULL\n";
		cout<<"Children : ";
		for (int j=0; j < temp->children_cnt; j++) {
                        cout<<temp->children[j]->projName<<", ";
                }
                cout<<"NULL\n";
	}
}

int find_null_parent_index() {
	int size;
	struct node *temp;

	size = Nodes.size();
	for (int i=0; i<size; i++) {
		temp = Nodes[i];
		if (temp->parents_cnt == 0) {
			temp->parents_cnt = -1;
			return i;
		}
	}
	return -1;
}

vector<char> build_order() {
	vector<char> result;
	int count = 0, size, index;
	struct node *temp;

	size = Nodes.size();
	while (count < size) {
		index = find_null_parent_index();
		if (index == -1) {
			result.clear();
			return result;
		}
		temp = Nodes[index];
		result.push_back(temp->projName);
		count++;
		for (int i=0; i < temp->children_cnt; i++) {
			temp->children[i]->parents_cnt--;
		}
	}
	return result;
}

int main() {
	int nodes_cnt, stop;
	char proj, strt, end;
	struct node *temp, *temp1, *temp2;
	bool cnt;
	vector<char> result;

	cout<<"Enter no of projects : ";
	cin>>nodes_cnt;
	for (int i=0; i < nodes_cnt; i++) {
		cout<<"Enter the name of project : ";
		cin>>proj;
		temp = allocate_node(proj, nodes_cnt);
		Nodes.push_back(temp);
		Map[proj] = i;
	}
	cnt = true;
	while (cnt) {
		cout<<"Enter the dependencies\n";
		cout<<"Start proj : ";
		cin>> strt;
		cout<<"End proj : ";
		cin>>end;
		temp1 = Nodes[Map[strt]];
		temp2 = Nodes[Map[end]];
		temp1->children[temp1->children_cnt] = temp2;
		temp1->children_cnt++;
		temp2->parents[temp2->parents_cnt] = temp1;
		temp2->parents_cnt++;
		cout<<"Do you want to Continue(0 to stop) : ";
		cin>>stop;
		if (stop == 0)
			break;
	}
//	print_tree();
	result = build_order();
	if (result.size() == 0){
		cout<<"No Build Order\n";
	}
	for (int i=0; i < result.size(); i++) {
		cout<<result[i]<<", ";
	}
return 0;
}
