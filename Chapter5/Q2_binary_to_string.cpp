#include <iostream>

using namespace std;

string binary_to_string(double val) {
	int cnt = 0;
	string temp = ".";

	while (val && (cnt<32)) {
		val = val*2;
		if (val >= 1) {
			temp +="1";
			val -= 1;
		} else
			temp +="0";
		cnt++;
	}
	if (cnt == 32)
		return "ERROR";
	return temp;
}

int main() {
	double val;

	val = 0.893;
	cout<<"Binary Representation : "<<binary_to_string(val)<<"\n";
return 0;
}
