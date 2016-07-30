#include <iostream>
#include <stdlib.h>
#include <vector>
#include <deque>

using namespace std;

struct node {
	int val;
	bool visited;
};


bool Route_Between_Nodes(vector<vector<struct node> > AdjacencyList, int start, int end) {
	deque<struct node> Queue;
	struct node strt_node;

	strt_node = AdjacencyList[start][0];
	strt_node.visited = true;
	Queue.push_back(strt_node);
	while (Queue.size() > 0) {
		struct node temp_node;
		temp_node = Queue[0];
		Queue.pop_front();
		cout<<"Checking "<<temp_node.val<<" and "<<end<<"\n";
		if (temp_node.val == end)
			return true;
		for (int i = 1; i < AdjacencyList[temp_node.val].size(); i++) {
			if (!AdjacencyList[temp_node.val][i].visited) {
				cout<<"Inserting into Queue : "<<AdjacencyList[temp_node.val][i].val<<"\n";
				AdjacencyList[temp_node.val][i].visited = true;
				Queue.push_back(AdjacencyList[temp_node.val][i]);
			}
		}
	}
	return false;
}

void printAdjacencyList(vector<vector<struct node> > adjList) {
	int size;

	size = adjList.size();
	for (int i=1; i <= size; i++) {
		int adjSize;
		adjSize = adjList[i].size();
		for (int j=0; j < adjSize; j++) {
			cout<<adjList[i][j].val<<", ";
		}
		cout<<"\n";
	}
}

void constructAdjacencyList(vector<vector<struct node> >& AdjacencyList) {	
	int count;
	cout<<"Enter the number of nodes : ";
	cin>>count;
	vector<struct node> temp1;
	struct node temp_node1;
	temp_node1.val = 0;
        temp_node1.visited=false;
        temp1.push_back(temp_node1);
        AdjacencyList.push_back(temp1);
	for (int i=1;i <= count; i++) {
		vector<struct node> temp;
		struct node temp_node;
		temp_node.val = i;
		temp_node.visited=false;
		temp.push_back(temp_node);
		AdjacencyList.push_back(temp);
	}

	for (int i=1;i <= count; i++) {
		bool cntne=true;
		int neighbor;
		vector<struct node> temp;
		temp = AdjacencyList[i];
		while (cntne) {
			cout<<"Enter the neighbor of node : "<<i<<" (0 to skip to next node): ";
			cin>>neighbor;
			if (neighbor == 0)
				break;
			temp.push_back(AdjacencyList[neighbor][0]);
		}
		AdjacencyList[i] = temp;
	}
}

int main() {
	vector<vector<struct node> > AdjacencyList;
	constructAdjacencyList(AdjacencyList);
	printAdjacencyList(AdjacencyList);
	cout<<"Is there a route between 1 and 6 : "<<Route_Between_Nodes(AdjacencyList, 1, 6)<<"\n";
return 0;
}
