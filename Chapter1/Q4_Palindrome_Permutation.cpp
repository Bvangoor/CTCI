/*Palindrome Permuattion : Check if the string is a pemutation of palindrome*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void palindrome_permutation_map(string A) {
	unordered_map<char, int> Map;
	int unique = 0, len, cnt = 0;

	len = A.length();
	for (int i = 0; i < len; i++) {
		if (A[i] != ' ') {
			cnt++;
			if (Map.count(tolower(A[i]))) {
				Map[tolower(A[i])] -= 1;
				if (Map[tolower(A[i])] == 0)
					unique--;
			} else {
				Map[tolower(A[i])] = 1;
				unique++;
			}
		}
	}
//	cout<<"unique : "<<unique<<"\n";
	if (cnt%2 == 0 && unique == 0)
		cout<<"Yes it is a permutation of a palindrome \n";
	else if (cnt%2 == 1 && unique == 1)
		cout<<"Yes it is a permutation of a palindrome \n";
	else
		cout<<"No it is not a permutation of a palindrome\n";
}

void palindrome_permutation_bitvector(string A) {
	int bitvector = 0, unique = 0, len, cnt = 0;
	
	len = A.length();
	for (int i = 0; i < len; i++) {
		if (A[i] != ' ') {
			cnt++;
			if (bitvector & (1<<(toupper(A[i])-'A'))) {
				bitvector = bitvector & ~(1<<(toupper(A[i])-'A'));
				unique--;
			} else {
				bitvector = bitvector | (1<<(toupper(A[i])-'A'));
				unique++;
			}
		}
	}
	if (cnt%2 == 0 && unique == 0)
                cout<<"Yes it is a permutation of a palindrome \n";
        else if (cnt%2 == 1 && unique == 1)
                cout<<"Yes it is a permutation of a palindrome \n";
        else
                cout<<"No it is not a permutation of a palindrome\n";
}

int main() {
	palindrome_permutation_bitvector("Tact Coa");
//	palindrome_permutation_bitvector("A B C A B D");
return 0;
}
