#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;


struct node {
	int x;
	int y;
};

void print_list(vector<struct node>& list) {

	for (int i=0; i < list.size(); i++)
		cout<<"Elem : "<<i+1<<" : "<<list[i].x<<" "<<list[i].y<<"\n";
}

struct Custom_Comp
{
	bool operator()(const node &box1, const node &box2) const {
		if ((box1.x > box2.x) && (box1.y > box2.y))
			return true;
		return false;
	}
};


int main() {
	vector<node> list;

	struct node box1;
	box1.x = 10;
	box1.y = 20;
	list.push_back(box1);
	
	struct node box2;
	box2.x = 30;
	box2.y = 40;
	list.push_back(box2);
	
	print_list(list);
	sort(list.begin(), list.end(), Custom_Comp());
	cout<<"After sort\n";
	print_list(list);

return 0;
}
