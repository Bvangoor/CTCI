#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void Rotate_Matrix_by_90(vector<vector<int> >& Matrix) {
	int rows = 0, columns = 0, n = 0, strt = 0, end;
	
	rows = Matrix.size();
        if (rows > 0)
                columns = Matrix[0].size();

	if (rows == columns)
		n = rows;
	end = n-1;
	
	while (n != 0 && n != 1) {
		int shift, temp = -1, temp1;
		shift = n-1;
		for (int i = 0; i < n-1; i++) {
			int curr_x, curr_y, next_x, next_y;
			curr_x = strt + 0;
			curr_y = strt + i;
			/*case 1: Move right(so y changes)*/
			if (curr_y + shift <= end) {
				next_x = curr_x;
				next_y = curr_y + shift;
			} else {
				/*move as much as to right and then remaining down*/
				next_x = curr_x + (curr_y + shift) - end;
				next_y = end;
			}
			temp = Matrix[next_x][next_y];
//			cout<<"curr : "<<Matrix[curr_x][curr_y]<<" replace : "<<Matrix[next_x][next_y]<<"\n";
			Matrix[next_x][next_y] = Matrix[curr_x][curr_y];
			curr_x = next_x;
			curr_y = next_y;
			/*case 2 : Move Down (So x changes)*/
			if (curr_x + shift <= end) {
				next_x = curr_x + shift;
				next_y = curr_y;
			} else {
				/*Move down as much as posible nd then remaining left*/
				next_y = curr_y - ((curr_x + shift) - end);
				next_x = end;
			}
//			cout<<"curr : "<<temp<<" replace : "<<Matrix[next_x][next_y]<<"\n";
			temp1 = Matrix[next_x][next_y];
			Matrix[next_x][next_y] = temp;
			temp = temp1;
			curr_x = next_x;
                        curr_y = next_y;
			/*Case 3 : Move Left (So y changes)*/
			if (curr_y - shift >= strt) {
				next_y = curr_y - shift;
				next_x = curr_x;
			} else {
				/*Move as much as to left and then go UP*/
				next_x = curr_x - (strt - (curr_y - shift));
				next_y = strt;
			}
//			cout<<"curr : "<<temp<<" replace : "<<Matrix[next_x][next_y]<<"\n";
			temp1 = Matrix[next_x][next_y];
			Matrix[next_x][next_y] = temp;
			temp = temp1;
			curr_x = next_x;
                        curr_y = next_y;
			/*Case 4 : Move UP (so x changes)*/
			if (curr_x - shift >= strt) {
				next_x = curr_x - shift;
				next_y = curr_y;
			} else {
				/*Move as much as to up and then go right*/
				next_y = curr_y + (strt - (curr_x - shift));
				next_x = strt;
			}
//			cout<<"curr : "<<temp<<" replace : "<<Matrix[next_x][next_y]<<"\n";
			Matrix[next_x][next_y] = temp;
		}
		n -= 2;
//		cout<<"value of n : "<<n<<"\n";
		strt += 1;
		end -= 1; 
	}
	
}

void print_matrix(vector<vector<int> >& Matrix) {
	int rows = 0, columns = 0;

	rows = Matrix.size();
	if (rows > 0)
		columns = Matrix[0].size();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout<<Matrix[i][j]<<"	";
		}
		cout<<"\n";
	}
}

int main() {
	vector<vector<int> > Matrix;
	vector<int> temp;
	/*Matrix initialisation*/
	temp.push_back(1);
	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(4);
	temp.push_back(5);
	Matrix.push_back(temp);
	temp.clear();
	temp.push_back(16);
	temp.push_back(17);
	temp.push_back(18);
	temp.push_back(19);
	temp.push_back(6);
	Matrix.push_back(temp);
	temp.clear();	
	temp.push_back(15);
	temp.push_back(24);
	temp.push_back(25);
	temp.push_back(20);
	temp.push_back(7);
	Matrix.push_back(temp);
	temp.clear();
	temp.push_back(14);
	temp.push_back(23);
	temp.push_back(22);
	temp.push_back(21);
	temp.push_back(8);
	Matrix.push_back(temp);
	temp.clear();
	temp.push_back(13);
	temp.push_back(12);
	temp.push_back(11);
	temp.push_back(10);
	temp.push_back(9);
	Matrix.push_back(temp);
	temp.clear();
	print_matrix(Matrix);
	Rotate_Matrix_by_90(Matrix);
	print_matrix(Matrix);
	
return 0;
}
