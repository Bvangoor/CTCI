#include <iostream>
#include <vector>
#include <string>

using namespace std;

int true_DP[100][100];
int false_DP[100][100];

int calculate_true_expr_val(char expr, int true_left, int false_left, int true_right, int false_right) {
	if (expr == '|') {
		return (true_left*true_right)+(true_left*false_right)+(false_left*true_right);
	} else if (expr == '&') {
		return (true_left*true_right);
	} else if (expr == '^') {
		return (true_left*false_right)+(false_left*true_right);
	}
	return -1;
}

int calculate_false_expr_val(char expr, int true_left, int false_left, int true_right, int false_right) {
	if (expr == '|') {
                return (false_left*false_right);
        } else if (expr == '&') {
                return (false_left*false_right)+(true_left*false_right)+(false_left*true_right);
        } else if (expr == '^') {
                return (true_left*true_right)+(false_left*false_right);
        }
	return -1;
}

void recursive_func(vector<char>& expr, int strt, int end) {
	int true_left, false_left, true_right, false_right;
	int sum_true, sum_false;

	true_left = false_left = true_right = false_right = 0;
	sum_true = sum_false = 0;
	if (true_DP[strt][end] >= 0 || false_DP[strt][end] >= 0)
		return ;
	for (int i=strt+1; i < end; i = i+2) {
		recursive_func(expr, strt, i-1);
		recursive_func(expr, i+1, end);

		true_left = true_DP[strt][i-1];
		false_left = false_DP[strt][i-1];
		true_right = true_DP[i+1][end];
		false_right = false_DP[i+1][end];

		sum_true += calculate_true_expr_val(expr[i], true_left, false_left, true_right, false_right);
		sum_false += calculate_false_expr_val(expr[i], true_left, false_left, true_right, false_right);
	}
	true_DP[strt][end] = sum_true;
	false_DP[strt][end] = sum_false;
}


void print_expr(vector<char>& expr){
	int len;

	len = expr.size();
	for (int i=0; i < len; i++)
		cout<<expr[i]<<" ";
	cout<<"\n";
}

int main() {
	vector<char> expr;
	int len;
	char desired = '1';

	expr.push_back('0');
	expr.push_back('&');
	expr.push_back('0');
	expr.push_back('&');
	expr.push_back('0');
	expr.push_back('&');
	expr.push_back('1');
	expr.push_back('^');
	expr.push_back('1');
	expr.push_back('|');
	expr.push_back('0');

	print_expr(expr);

	len = expr.size();

	memset(true_DP, -1, sizeof(true_DP));
	memset(false_DP, -1, sizeof(false_DP));
	for (int i=0; i < len; i++) {
		if (expr[i] == '1') {
			true_DP[i][i] = 1;
			false_DP[i][i] = 0;
		} else if (expr[i] == '0') {
			false_DP[i][i] = 1;
			true_DP[i][i] = 0;
		}
	}
	recursive_func(expr, 0, len-1);
	
	if (desired == '1')
		cout<<"Answer for "<<desired<<" is : "<<true_DP[0][len-1]<<"\n";
	else
		cout<<"Answer for "<<desired<<" is : "<<false_DP[0][len-1]<<"\n";
		
return 0;
}
