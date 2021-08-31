#include <iostream>

constexpr int moduler = 1000000007;

using namespace std;

unsigned long long getInverseNi(int a, int x = moduler - 2) {
	if (x == 0)
		return 1;
	if (x == 1)
		return a;
	if (x % 2 == 0) {
		unsigned long long ans = getInverseNi(a, x / 2) % moduler;
		return (ans * ans) % moduler;
	}
	else {
		unsigned long long ans = getInverseNi(a, x / 2) % moduler;
		return ans * ans % moduler * a % moduler;
	}
}
int main(void) {
	unsigned long long answer = 0;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int ni, si;
		cin >> ni >> si;
		
		int q = (getInverseNi(ni) * si) % moduler;

		answer += q;
		answer %= moduler;
	}

	cout << answer;

	return 0;
}