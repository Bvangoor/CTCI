#include <iostream>

using namespace std;

int conversion(int A, int B) {
	int res = 0;
	int C;

	C = A^B;

	while (C) {
		if ((C&1))
			res++;
		C = C>>1;
	}
	return res;
}

int main() {
	int A, B;

	A = 29; /* 11101 */
	B = 15; /* 01111 */

	cout<<"Conversion : "<<conversion(29, 15)<<"\n";
return 0;
}
