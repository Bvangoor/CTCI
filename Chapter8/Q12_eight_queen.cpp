#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int> > get_free_list(vector<vector<bool> > helper) {
	int rows;
	int columns;
	vector<pair<int, int> > result;

	rows = helper.size();
	if (rows)
		columns = helper[0].size();

	for (int i=0; i < rows; i++) {
		for (int j=0; j < columns; j++) {
			if (helper[i][j]) {
				pair<int, int> temp_pair;
				temp_pair.first = i;
				temp_pair.second = j;
				result.push_back(temp_pair);
			}
		}
	}
	return result;
}

void mark_rows_columns_diagonals(vector<vector<bool> >& temp_helper, int pos1, int pos2, int rows, int columns) {

	temp_helper[pos1][pos2] = false;
	for (int j = 0; j < columns; j++) /* Make all columns False*/
		temp_helper[pos1][j] = false;
	for (int j = 0; j < rows; j++)    /* Make all rows False*/
		temp_helper[j][pos2] = false;
//	cout<<"Properly done the rows and columns : "<<rows<<", "<<columns<<"\n";
	/* Make diagonals False*/
	int temp_i, temp_j;
	temp_i = pos1;
	temp_j = pos2;
	while (temp_i >=0 && temp_j >= 0) {
//		cout<<"1 : temp_i "<<temp_i<<" temp_j "<<temp_j<<"\n";
		temp_helper[temp_i][temp_j] = false;
		temp_i -= 1;
		temp_j -= 1;
	}
	temp_i = pos1;
	temp_j = pos2;
	while (temp_i < rows && temp_j < columns) {
//		cout<<"2 : temp_i "<<temp_i<<" temp_j "<<temp_j<<"\n";
		temp_helper[temp_i][temp_j] = false;
		temp_i += 1;
		temp_j += 1;
	}
	temp_i = pos1;
	temp_j = pos2;
	while (temp_i >= 0 && temp_j < columns) {
//		cout<<"3 : temp_i "<<temp_i<<" temp_j "<<temp_j<<"\n";
		temp_helper[temp_i][temp_j] = false;
		temp_i -= 1;
                temp_j += 1;
	}
	temp_i = pos1;
	temp_j = pos2;
	while (temp_i < rows && temp_j >= 0) {
//		cout<<"4 : temp_i "<<temp_i<<" temp_j "<<temp_j<<"\n";
		temp_helper[temp_i][temp_j] = false;
		temp_i += 1;
		temp_j -= 1;
       	}
	return ;
}

void recur_arrange_queens(int queens, vector<vector<bool> > helper, vector< vector<pair<int, int> > >& result, vector<pair<int, int> > assignment) {
	if (queens == 0) {
		result.push_back(assignment);
		return ;
	}
	vector<pair<int, int> > free_list;
	int rows, columns;
	rows = helper.size();
	if (rows)
		columns = helper[0].size();

	free_list = get_free_list(helper);
	for (int i = 0; i < free_list.size(); i++) {
		pair<int, int> temp_pair;
		vector<vector<bool> > temp_helper;
		vector<pair<int, int> > temp_assignment;
		int pos1, pos2;
		
		temp_assignment = assignment;
		temp_pair.first = pos1 = free_list[i].first;
		temp_pair.second = pos2 = free_list[i].second;
		temp_assignment.push_back(temp_pair);
//		assignment.push_back(temp_pair);

		temp_helper = helper;		
		mark_rows_columns_diagonals(temp_helper, pos1, pos2, rows, columns);

		recur_arrange_queens(queens-1, temp_helper, result, temp_assignment);
	}
	return ;
}

void print_assignments(vector< vector<pair<int, int> > >& result) {
	int assignments;
	vector<pair<int, int> > assignment;
	pair<int, int> temp_pair;

	assignments = result.size();
	for (int i=0; i < assignments; i++) {
		cout<<"===============\n";
		assignment = result[i];
		for (int j=0; j < assignment.size(); j++) {
			temp_pair = assignment[j];
			cout<<"("<<temp_pair.first<<", "<<temp_pair.second<<")\n";
		}
		cout<<"===============\n";	
	}
}

int main() {
	int queens = 4;
	int rows  = 4;
	int columns = 4;
	vector< vector<pair<int, int> > > result;
	vector<pair<int, int> > assignment;
	vector<vector<bool> > helper;
	vector<bool> temp;

	for (int i=0; i < columns; i++)
		temp.push_back(true);

	for (int i = 0; i < rows; i++)
		helper.push_back(temp);

	recur_arrange_queens(queens, helper, result, assignment);

	print_assignments(result);
return 0;
}
