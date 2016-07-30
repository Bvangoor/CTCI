#include <iostream>

using namespace std;

unsigned insertion(unsigned M, unsigned N, int j, int i) {
	unsigned mask1 = -1;
	unsigned mask2 = -1;
	unsigned mask;

	mask1 = mask1<<(j+1);
	mask2 = mask2>>(32-i);
	mask = mask1|mask2;

	M = (M & mask)|(N<<i);
	return M;
}

int main() {
	unsigned int M = 1024;/*10000000000*/
	unsigned int N = 19; /*     10011*/
	unsigned result;      /*10001001100   --> 1100 (decimal)*/ 
	int i = 0;
	int j = 4;
	
	result = insertion(M, N, j, i);
	cout<<"Result : "<<result<<"\n";
}
