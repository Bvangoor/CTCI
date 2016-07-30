#include <iostream>
#include <vector>
#include <string>
using namespace std;


void print_in_bits(unsigned char byte) {
	int i = 0;
	string temp = "";

	while (i < 8) {
		if (byte & (1<<i))
			temp += "1";
		else
			temp += "0";
		i++;
	}
	reverse(temp.begin(), temp.end());
	cout<<temp;
}

void print_bytes(vector<unsigned char> &A, int width) {
	int rows, columns;

	columns = width/8;
	rows = A.size();

	for (int i = 0; i < rows; i++) {
		if (i && i%columns == 0)
			cout<<"\n";
		print_in_bits(A[i]);
		cout<<" ";
	}
	cout<<"\n";
}

void draw_line(vector<unsigned char>& A, int width, int x1, int x2, int y) {
	int index1, index2;
	int bit1, bit2;
	unsigned char mask1, mask2;

	index1 = (y*width + x1)/8;
	index2 = (y*width + x2)/8;

	bit1 = (y*width + x1) - (index1*8);
	bit2 = (y*width + x2) - (index2*8);

	for (int i = index1+1; i < index2; i++)
		A[i] = 255;

	mask1 = (1<<(8-bit1))-1;
	A[index1] = A[index1] | mask1;

	mask2 = 255<<(7-bit2);
	A[index2] = A[index2] | mask2;
}


int main() {
	vector<unsigned char> A;
	int width = 64, x1, x2, y;

	for (int j=0; j < 16; j++)
		A.push_back(0);
	
	print_bytes(A, width);

	x1 = 23;
	x2 = 44;
	y = 0;
	draw_line(A, width, x1, x2, y);
	cout<<"After drainwg the line from ("<<x1<<", "<<y<<") to ("<<x2<<", "<<y<<") : \n";
	print_bytes(A, width);

	return 0;
}
