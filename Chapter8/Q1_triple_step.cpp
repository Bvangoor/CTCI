#include <iostream>

using namespace std;

unsigned long long int triple_step(int step) {
	unsigned long long int a, b, c, sum;

	if (step < 0) /* We don't go anyway if there are no steps */
		return 0;
	a = 1; /* We take 1 way to reach step1 */
	if (step == 1)
		return a;

	b = 2; /* We take 2 ways to reach step 2 */
	if (step == 2)
		return b;
	c = 1;
	for (int i = 3; i <= step; i++) {
		sum = a + b + c;
		a = b;
		b = c;
		c = sum;
	}
	return sum;
}

int main() {
	int step = 50;

	cout<<"No. of ways to go to step "<<step<<" is : "<< triple_step(step) <<"\n";
return 0;
}
