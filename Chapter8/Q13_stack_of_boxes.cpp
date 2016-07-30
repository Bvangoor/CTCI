#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct node {
	int width;
	int depth;
	int height;
};

struct Custom_Comp
{
	bool operator()(const node &box1, const node &box2) const {
		if ((box1.width * box1.depth * box1.height) > (box2.width * box2.depth * box2.height))
			return true;
		return false;
	}
};

int max_height(vector<struct node>& list) {
	int max_val = -1;
	int len;
	vector<int> height;

	len = list.size();
	sort(list.begin(), list.end(), Custom_Comp());
	for (int i=0; i<len; i++)
		height.push_back(list[i].height);

	for (int i=0; i < len; i++) {
		for (int j=0; j < i; j++) {
			if ((list[j].width > list[i].width) && (list[j].depth > list[i].depth) && (list[j].height > list[i].height))
				height[i] = max(height[i]+height[j], height[i]);
		}
		max_val = max(max_val, height[i]);
	}

	return max_val;
}

void print_boxes(vector<struct node>& list) {
	int cnt;

	cnt = list.size();
	for (int i=0; i < cnt; i++) {
		cout<<"Box "<<i+1<<" w : "<<list[i].width<<" d : "<<list[i].depth<<" h : "<<list[i].height<<"\n";
	}
}

int main() {
	int boxes = 4;
	vector<node> list;

	struct node box1 = {1, 2, 3};
	struct node box2 = {1, 1, 7};
	struct node box3 = {2, 1, 4};
	struct node box4 = {10, 12, 10};
	
	list.push_back(box1);
	list.push_back(box2);
	list.push_back(box3);
	list.push_back(box4);

	cout<<"Max possible height is : "<<max_height(list)<<"\n";
	
/*	print_boxes(list);
	sort(list.begin(), list.end(), Custom_Comp());
	cout<<"After Sort\n";
	print_boxes(list);
*/
return 0;
}
