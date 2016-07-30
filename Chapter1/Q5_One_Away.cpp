#include <iostream>
#include <string>

using namespace std;

void check_replacement(string A, string B) {
	int len;
	bool found = false;

	len = A.length();
	for (int i=0; i < len; i++) {
		if (A[i] != B[i]) {
			if (found) {
				cout<<"No one edit distance away\n";
				return ;
			}
			found = true;
		}
	}	
	cout<<"Yes one edit distance away\n";
}

void check_insrt_del(string A, string B) {
	int len1, len2, indx1 = 0, indx2 = 0;
	

	len1 = A.length();
	len2 = B.length();

	while (indx1 < len1 && indx2 < len2) {
		if (A[indx1] != B[indx2]) {
			if (indx1 == indx2) {
				indx1++;
			} else {
				cout<<"No one edit distance away\n";
				return ;	
			}
		} else {
			indx1++;
			indx2++;
		}
	}
	cout<<"Yes one edit distance away\n";
}

void Check_One_Away(string A, string B) {
	int len1, len2;
	
	len1 = A.length();
	len2 = B.length();
	if (len1 == len2) {
		check_replacement(A, B);
		return ;
	}
	else if (len1+1 == len2) {
		check_insrt_del(B, A);
		return ;
	}
	else if (len2+1 == len1) {
		check_insrt_del(A, B);
		return ;
	}
	cout<<"No one edit distance away\n";
	return ;
}

int main() {
	string A = "bake";
	string B = "pae";
	Check_One_Away(A, B);
return 0;
}
