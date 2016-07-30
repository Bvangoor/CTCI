/*Check permutation : Given two strings, A method to determine one is a permutation of other*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void check_permutation(string A, string B) {
	int len1, len2, unique = 0;
	unordered_map<char, int> Map;

	len1 = A.length();
	len2 = B.length();
	if (len1 != len2) {
		cout<<"Not a permutation\n";
		return ;
	}

	for (int i = 0; i < len1; i++) {
		if (Map.count(A[i])) {
			Map[A[i]] += 1;
		} else {
			Map[A[i]] = 1;
			unique++;
		}
	}

	for (int i = 0; i < len2; i++) {
		if (Map.count(B[i])) {
			Map[B[i]] -= 1;
			if (Map[B[i]] == 0)
				unique--;
		} else {
			cout<<"Not a permutation\n";
			return ;
		}
	}

	if (unique)
		cout<<"Not a permutation\n";
	else
		cout<<"Strings are permutation\n";

}


int main() {
	check_permutation("A", "");
return 0;
}
