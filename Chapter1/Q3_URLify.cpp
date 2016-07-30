/*URLify : Replace all the spaces in the string with '%20'*/
#include <iostream>
#include <string>

using namespace std;

void URLify(char *A, int len) {
	int spaces = 0, read_indx, write_indx;
	/*find # of spaces*/
	for (int i = 0; i < len; i++) {
		if (A[i] == ' ')
			spaces++;
	}
	if (spaces == 0) {
		cout<<"No need to edit anything\n";
		return ;
	}

	/*Start writing from end*/
	write_indx = len - spaces + (3*spaces) - 1;
	read_indx = len - 1;
	A[write_indx+1] = '\0';
	while (read_indx >= 0) {
		if (A[read_indx] == ' ') {
			A[write_indx] = '0';
			A[write_indx-1] = '2';
			A[write_indx-2] = '%';	
			write_indx -= 3;
			read_indx -= 1;
		} else {
			A[write_indx] = A[read_indx];
			write_indx -= 1;
			read_indx -= 1;	
		}
	}
}

int main() {
	char *given;
//	given = (char *)malloc(18 * sizeof(char));
	given = (char *)malloc(34 * sizeof(char));
//	strncpy(given, "Mr John Smith", 13);
	strncpy(given, "   A  B  CDFG  ", 15);
	given[15] = '\0';
	cout<<"String before URLify : "<<given<<"\n";
	URLify(given, 15);
	cout<<"String after URLify : "<<given<<"\n";	
return 0;
}
