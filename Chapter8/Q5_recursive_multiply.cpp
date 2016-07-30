#include <iostream>

using namespace std;

int return_no_bits(int val) {
	int cnt = 0, temp = 2;
	if (val < temp)
		return cnt;
	while (val >= temp) {
		cnt++;
		temp +=temp;
	}
	return cnt;
}

int recursive_multiply(int n, int m) { /* n X m*/
	if (n == 0 || m == 0)
		return 0;

	int sum, recur_sum, bits;

	bits = return_no_bits(m);
	
	sum = n<<bits;
	recur_sum = recursive_multiply(n, m - (1<<bits));
	return (sum+recur_sum);
}

int recursive_multiply_perfect(int n, int m) {
	int smaller, bigger, recur_sum;

	smaller = (n <= m) ? n : m;
	bigger  = (n >= m) ? n : m;

	if (smaller == 0)
		return 0;
	if (smaller == 1)
		return bigger;

	recur_sum = recursive_multiply(smaller/2, bigger);

	if (smaller%2 == 0)
		return (recur_sum<<1);
	else
		return ((recur_sum<<1)+bigger);
}

int main() {
	int n = 50, m = 100;

	cout<<"Recursive Multiplication of "<<n<<" and "<<m<<" : "<<recursive_multiply_perfect(n, m)<<"\n";
	return 0;
}
