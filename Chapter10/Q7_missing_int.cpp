#include <iostream>
#include <string>

using namespace std;

/* I'm only checking number from 1 to 64, but missing one number */

int find_zeroth_bit(int num) {
	int i;

	for ( i = 1; i <= 32; i++) {
		if (!(num & (1<<(i-1))))
			break;
	}

	return i;
}

int main() {
	unsigned int bit_vect[10]; /* each int represent 32 numbers */
	int missing = 32;
	int div, rem, bit;
	int missing_num = 0;

	memset(bit_vect, 0, sizeof(bit_vect));

//	cout<<"val of bit_vat[0] : "<<bit_vect[0]<<"\n";

	for (int i=1; i <= 64; i++) {
		if (i == missing) {
			/* Don't do */
		} else {
			div = i / 32;
			rem = i % 32;
			if (rem == 0)
				div = div - 1;
			bit_vect[div] = bit_vect[div] | (1 << (rem - 1));
		}
	}
//	cout<<"val of bit_vat[0] : "<<bit_vect[0]<<"\n";
	/* Find the missing number */
	for (int i=0; i < 10; i++) {
		if (bit_vect[i] != 4294967295) {
			bit = find_zeroth_bit(bit_vect[i]);
//			cout<<"Val of i : "<<i<<" and bit obtained : "<<bit<<"\n";
			missing_num += bit;
			cout<<"Missing num : "<<missing_num<<"\n";
			break;
		}
		missing_num += 32;
	}

return 0;
}
