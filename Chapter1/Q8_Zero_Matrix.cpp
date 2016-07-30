#include <iostream>
#include <vector>

using namespace std;

void zero_matrix(vector<vector<int> >& Matrix) {
	int rows = 0, columns = 0, rows_zero = 0, columns_zero = 0;
	
	rows = Matrix.size();
	if (rows > 0)
		columns = Matrix[0].size();

	for (int i = 0; i < columns; i++) {
		if (Matrix[rows-1][i] == 0)
			rows_zero = 1;
	}

	for (int i = 0; i < rows; i++) {
                if (Matrix[i][columns-1] == 0)
                        columns_zero = 1;
        }

	for (int i = 0; i < rows-1; i++) {
		for (int j = 0; j < columns-1; j++) {
			if (Matrix[i][j] == 0) {
				Matrix[i][columns-1] = 0;
				Matrix[rows-1][j] = 0;
			}
		}
	}
	
	for (int i = 0; i < rows-1; i++) {
		for (int j = 0; j < columns-1; j++) {
			Matrix[i][j] = Matrix[i][columns-1] & Matrix[rows-1][j];
		}
	}
	if (rows_zero) {
		for (int i = 0; i < columns; i++)
			Matrix[rows-1][i] = 0;
	}
	if (columns_zero) {
		for (int i = 0; i < rows; i++)
			Matrix[i][columns-1] = 0;
	}
}

void print_matrix(vector<vector<int> >& Matrix) {
        int rows = 0, columns = 0;

        rows = Matrix.size();
        if (rows > 0)
                columns = Matrix[0].size();

        for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                        cout<<Matrix[i][j]<<"   ";
                }
                cout<<"\n";
        }
}

int main() {
	vector<vector<int> > Matrix;
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(0);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(0);
	Matrix.push_back(temp);
	temp.clear();	
	temp.push_back(0);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(0);
	Matrix.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	Matrix.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(0);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	Matrix.push_back(temp);
	temp.clear();
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	temp.push_back(1);
	Matrix.push_back(temp);
	temp.clear();
	cout<<"Input : \n";
	print_matrix(Matrix);
	zero_matrix(Matrix);
	cout<<"Output : \n";
	print_matrix(Matrix);
return 0;
}
