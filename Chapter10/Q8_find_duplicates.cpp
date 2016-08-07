#include <iostream>
#include <vector>
using namespace std;

void find_duplicates(vector<int>& input) {
	unsigned int bit_vect[1024]; /* 4KB of memory */
	int div, rem;
	int val;

	memset(bit_vect, 0, sizeof(bit_vect));
	for (int i=0; i < input.size(); i++) {
		div = input[i] / 32;
		rem = input[i] % 32;

		if (rem == 0) {
			div = div - 1;
			rem = 32;
		}

		if (bit_vect[div] & (1 << (rem-1)))
			cout<<"duplicate : "<<input[i]<<"\n";
		else
			bit_vect[div] = bit_vect[div] | (1 << (rem-1));
	}
}


int main() {
	vector<int> input;

	for (int i=1; i <= 100; i++) {
		input.push_back(i);
	}
/*	input.push_back(90);
	input.push_back(9);
	input.push_back(91);
	input.push_back(92);
	input.push_back(93);
	input.push_back(94);
	input.push_back(95);
	input.push_back(96);
	input.push_back(97);
	input.push_back(98);
	input.push_back(99); */
	
	find_duplicates(input);
return 0;
}
