#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

void print_the_paths(vector<string> Paths) {
	int paths;

	paths = Paths.size();
	for (int i = 0; i < paths; i++)
		cout<<Paths[i]<<"END\n";
}

vector<vector< vector<string> > > rob_in_the_grid(vector<vector<int> >& Matrix) {
	int rows, columns;

	rows = Matrix.size();
	if (rows > 0)
		columns = Matrix[0].size();

	vector<string> temp(1, "");
	vector< vector <string> > temp1(columns, temp);
	vector< vector <vector <string> > > DP(rows, temp1);

	for (int i=0; i < rows; i++) {
		for (int j=0; j < columns; j++) {
			if (Matrix[i][j]) {
				string current = "("+to_string(i)+", "+to_string(j)+"), ";
				vector<string> top, left;
				if (i-1 >= 0 && Matrix[i-1][j] != 0) { /* from top */
					top = DP[i-1][j];
					if (top.size() > 0 && top[0].length() > 0) {
						for (int k=0; k < top.size(); k++) {
							top[k] += "->";
							top[k] += current;
						}
					}
				}
				if (j-1 > 0 && Matrix[i][j-1] != 0) { /* from left */
					left = DP[i][j-1];
					if (left.size() > 0 && left[0].length() > 0) {
						for (int k=0; k < left.size(); k++) {
                                                        left[k] += current;
                                                }
					}
				}
				vector<string> curr_assign;
				for (int l = 0; l < left.size(); l++)
					curr_assign.push_back(left[l]);
				for (int m=0; m < top.size(); m++)
					curr_assign.push_back(top[m]);
				if (i == 0 && j == 0)
					curr_assign.push_back(current);
				DP[i][j] = curr_assign;
				cout<<"i : "<<i<<" j : "<<j-1<<"(Left) : \n";
				if (i-1 > 0 && j-1 > 0)
					print_the_paths(DP[i][j-1]);
				cout<<"i : "<<i-1<<" j : "<<j<<"(top) : \n";
				if (i-1 > 0 && j-1 > 0)
					print_the_paths(DP[i-1][j]);
				cout<<"i : "<<i<<" j : "<<j<<"(curr) : \n";
				print_the_paths(DP[i][j]);
			}
		}
	}
	return DP;
}


void print_matrix(vector<vector<int> > & Matrix) {
	int rows, columns;

	rows = Matrix.size();
	if (rows > 0)
		columns = Matrix[0].size();

	for (int i=0; i < rows; i++) {
		for (int j=0; j< columns; j++) {
			cout<<Matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main() {
	vector<int> temp (2, 1);
	vector<vector<int> > Matrix (2, temp); /* 4x4 Matrix*/
	vector<vector< vector<string> > > result;

	/* obstacles */
/*	Matrix[0][3] = 0;
	Matrix[1][1] = 0;
	Matrix[2][2] = 0;
	Matrix[3][1] = 0; */
	print_matrix(Matrix);
	result = rob_in_the_grid(Matrix);
	cout<<"Answer : \n";
	print_the_paths(result[3][3]);
return 0;
}
