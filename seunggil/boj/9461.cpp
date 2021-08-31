#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	long long dp[100] = { 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };
	int size = 10;

	while (N--) {
		int p;
		cin >> p;

		if (p <= size)
			cout << dp[p - 1] << '\n';
		else {
			for (int i = size; i < p; i++)
				dp[i] = dp[i - 1] + dp[i - 5];
			size = p;
			cout << dp[p - 1] << '\n';
		}
	}
	
	return 0;
}