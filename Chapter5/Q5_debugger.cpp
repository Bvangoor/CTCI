#include <iostream>

using namespace std;

bool is_power_of_2(unsigned num) {
	if (!(num & (num-1)))
		return true;
	else
		return false;
}

int main() {
	unsigned num;
	num = 1;

	cout<<"Is number : "<<num<<" power of 2 : "<<((is_power_of_2(num))?"true\n":"false\n");

}
