#include <iostream>

using namespace std;


unsigned next_smallest(unsigned num) {
	unsigned temp = num, mask;
	int cnt = 1, ones = 0, pos = 0;

	while (temp) {
		if (temp&1)
			ones++;
		if (!(temp&1) && (temp&2))
			break;
		temp = temp >> 1;
		cnt++;
	}

	num = (num) & (~(1<<(cnt))); /* Flip bit 1 to 0*/

	pos = cnt;
	ones = ones+1;
	if (ones == 1)
		mask = 1<<(pos-1);
	else
		mask = ((1<<ones) - 1)<<(pos-ones);

	num = (num) & ~((1<<cnt)-1);
	num = (num) | mask;
	
	return num;
}	

unsigned next_largest(unsigned num) {
	unsigned temp = num, mask;
	int cnt = 1, ones = 0;

	while (temp) {
		if (temp&1)
			ones++;
		if (!(temp&2) && (temp&1))
			break;
		temp = temp >> 1;
		cnt++;
	}
//	cout<<"cnt : "<<cnt<<"\n";
	num = (num) | (1<<(cnt)); /* Flip bit 0 to 1 */
//	cout<<"num : "<<num<<"\n";
	num = (num) & ~((1<<cnt)-1);
//	cout<<"num : "<<num<<"\n";
//	cout<<"ones : "<<ones<<"\n";
	ones = ones-1;
	if (ones == 1)
		mask = 1;
	else
		mask = (1<<ones)-1;
	num = (num) | mask;
	return num;
}

int main() {
//	unsigned number = 29; /* 11101 */
	unsigned number = 105; /* 11110 */

	cout<<"Next smallest number than : "<<number<<" is : "<< next_smallest(number)<<"\n";
	cout<<"Next largest number than  : "<<number<<" is : "<< next_largest(number)<<"\n";
return 0;
}
