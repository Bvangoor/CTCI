#include <iostream>
#include <cmath>
using namespace std;

int flip_bit_to_win(unsigned number) {
	int max_val = 0, curr = 0, tmp = 0;
	bool found = false;

	if (!number)
		return 1;
	while (number) {
		if (number & 1 ) {
			if (found)
				tmp++;
			else
				curr++;
		} else {
			if (found) {
				max_val = max(max_val, curr+tmp);
				curr = tmp+1;
				tmp = 0;
			} else {
				found = true;
				curr++;
				tmp = 0;
			}
		}
		number = number>>1;
	}
	max_val = max(max_val, curr+tmp);
	return max_val;
}

int main() {
	unsigned number;
	number = 1775; /* 11011101111 */
	number = 375775; /* 1011011101111011111 */
	number = 512; /* 1000000000 */
	number = 0; /* 00000 */

	cout<<"Max contigous 1's length : "<<flip_bit_to_win(number)<<"\n";

return 0;
}
