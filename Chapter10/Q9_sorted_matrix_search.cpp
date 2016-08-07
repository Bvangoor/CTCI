#include <iostream>
#include <vector>

using namespace std;

void find_the_elem(vector<vector<int> >& matrix, int val) {
	int rows, columns;
	int i, j;

	rows = matrix.size();
	if (rows > 0)
		columns = matrix[0].size();
	i = rows-1;
	j = 0;

	while ( (i >= 0) && (j < columns) ) {
		if (matrix[i][j] == val) {
			cout<<"Found at index : "<<i<<" "<<j<<"\n";
			goto out;
		} else if (val > matrix[i][j]) {
			j++;
		} else {
			i = i-1;
		}
	}
	cout<<"Not found\n";
out:
	return ;
}

int main() {
	vector<int> temp;
	vector<vector<int> > matrix;

	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(4);
	temp.push_back(5);
	matrix.push_back(temp);
	temp.clear();
	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(4);
	temp.push_back(5);
	temp.push_back(6);
	matrix.push_back(temp);
	temp.clear();
	temp.push_back(3);
	temp.push_back(4);
	temp.push_back(5);
	temp.push_back(6);
	temp.push_back(7);
	matrix.push_back(temp);
	temp.clear();
	temp.push_back(4);
	temp.push_back(5);
	temp.push_back(6);
	temp.push_back(7);
	temp.push_back(8);
	matrix.push_back(temp);
	temp.clear();
	temp.push_back(5);
	temp.push_back(6);
	temp.push_back(7);
	temp.push_back(8);
	temp.push_back(9);
	matrix.push_back(temp);
	temp.clear();
	find_the_elem(matrix, 10);
return 0;
}
