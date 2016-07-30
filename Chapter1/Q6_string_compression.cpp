#include <iostream>
#include <string>

using namespace std;

void string_compression(string A) {
	int len;
	string result = "";
	
	len = A.length();
	for (int i=0; i < len;) {
		int j, count;
		result += A[i];
		count = 1;
		j = i+1;
		while (j < len) {
			if (A[j] == A[i])
				count++;
			else
				break;
			j++;
		}
		result += to_string(count);
		i = j;
	}
	if (result.length() < len) {
		cout<<"Original : "<<A<<"\n";
		cout<<"Compressed : "<<result<<"\n";
	} else
		cout<<"No Compression\n";
return ;
}

int main() {
	string A = "aabbaaaaaaaaaa";
	string_compression(A);
return 0;
}
