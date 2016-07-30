#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_array(vector<int>& array) {
	int len;

	len = array.size();
	for (int i = 0; i < len; i++)
		cout<<array[i]<<" ";
	cout<<"\n";
}

/* A has space at its end to merge B into it */
void sorted_merge(vector<int>& A, vector<int>& B, int A_len, int B_len) {
	int shift;
	int A_elems;
	int temp1, temp2; /* used in shifting */

	shift = B_len;
	A_elems = min(A_len, shift);

	/* pre-process shift A elems to end */
	for (int i = 0; i < A_elems; i++) {
		int shift_indx;
		
		shift_indx = i + shift;
		temp1 = A[i];
		while (shift_indx < A_len) {
			temp2 = A[shift_indx];
			A[shift_indx] = temp1;
			temp1 = temp2;
			shift_indx += shift;
		}
	}

	int indx1, indx2, curr, rem;

	indx2 = curr = 0; /* Starting indexes in A and B*/
	indx1 = shift;    /* Starting index to compare in A*/


	while ((indx1 < A_len) && (indx2 < B_len)) {
		if (A[indx1] < B[indx2]) {
			A[curr] = A[indx1];
			indx1++;
		} else {
			A[curr] = B[indx2];
			indx2++;
		}
		curr++;
	}

	rem = B_len - indx2;
	for (int i = 0; i < rem; i++)
		A[curr + i] = B[indx2 + i];

}

/* A Better approach is to start copying from last i.e Use the max elem and fill from last*/
void sorted_merge(vector<int>& A, vector<int>& B, int A_len) {
	int indx1, indx2, curr, rem;

	indx1 = A_len - 1;
	indx2 = B.size() - 1;
	curr = A.size() - 1;

	while ((indx1 >= 0) && (indx2 >= 0)) {
		if (A[indx1] > B[indx2]) {
			A[curr] = A[indx1];
			indx1--;
		} else {
			A[curr] = B[indx2];
			indx2--;
		}
		curr--;
	}

	rem = indx2 + 1;

	for (int i = 0; i < rem; i++)
		A[curr - i] = B[indx2 - i];
}

int main() {
	vector<int> A (6, 0);
	vector<int> B (3, 0);

	A[0] = 4;
	A[1] = 5;
	A[2] = 6;
	
	B[0] = 1;
	B[1] = 2;
	B[2] = 3;
	
	print_array(A);
	print_array(B);

//	sorted_merge(A, B, A.size(), B.size());
	sorted_merge(A, B, 3);

	print_array(A);
return 0;
}
