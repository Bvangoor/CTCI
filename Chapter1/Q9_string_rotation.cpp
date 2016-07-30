#include <iostream>
#include <string>

using namespace std;

void string_rotation(string A, string B) {
	string temp = "";

	if (A.length() != B.length()) {
		cout<<"NO rotation\n";
		return ;
	}

	temp += B;
	temp += B;
	if (temp.find(A) != string::npos)
		cout<<"YES rotation\n";
	else
		cout<<"NO rotation\n";
}

int main() {
	string A = "waterbottle";
	string B = "erbottlewat";

	string_rotation(A, B);
}
