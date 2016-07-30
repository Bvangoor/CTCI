#include <iostream>
#include <vector>

using namespace std;

int DP[100][100];

void print_DP(int Rupees, int coins) {
	for (int i=0; i <= Rupees; i++) {
		for (int j=0; j <= coins; j++)
			cout<<DP[i][j]<<" ";
		cout<<"\n";
	}
}

int Number_of_ways(int Rupees, vector<int>& coins) {
	int size;

	size = coins.size();

//	cout<<"Rupees : "<<Rupees<<" and coins size is : "<<size<<"\n";
	for (int i=0; i <= Rupees; i++)
		DP[i][0] = 0; /* We Don't have any coins */

	for (int i = 1; i <= size; i++)
		DP[0][i] = 1; /* We have 0 rupees but many coins, there is only one way to represent i.e Don't show */

	for (int i=1; i <= Rupees; i++ ) {
		for (int j=1; j <= size; j++) {
			if (coins[j] <= i) {
//				cout<<"Coin "<< coins[j] <<" is less than "<< i<<"\n";
				DP[i][j] = DP[i-coins[j]][j] + DP[i][j-1];
			 } else
				DP[i][j] = DP[i][j-1];
		}
	}
	print_DP(Rupees, size);
	return DP[Rupees][size];
}

int main() {
	int Rupees = 4;
	vector<int> coins;

	coins.push_back(-1);
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(3);
//	coins.push_back(6);

//	cout<<"Number of ways arraning Rupees : "<<Rupees<<" with given coins is : "<<Number_of_ways(Rupees, coins)<<"\n";
	Number_of_ways(Rupees, coins);

	return 0;
}
