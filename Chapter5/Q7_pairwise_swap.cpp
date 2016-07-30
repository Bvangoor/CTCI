#include <iostream>

using namespace std;

unsigned pairwise_swap(unsigned num) {
	unsigned oddmask = 0xaaaaaaaa;
	unsigned evenmask = 0x55555555;

	return ((num&evenmask)<<1) | ((num&oddmask)>>1);
}

int main() {
	unsigned num;

	num = 10;
	cout<<"pairwise swap of "<<num<<" is : "<<pairwise_swap(num)<<"\n";
return 0;
}
