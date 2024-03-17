#include <bits/stdc++.h>
using namespace std;
    
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
	int num;
	cin >> num;

	for (int i = 1; i < num; i++) {
		int tmp = i;
		int sum = i;

		while (tmp != 0) {
			sum += tmp % 10; // 1의 자리 더하기
			tmp /= 10;
		}

		if (sum == num) {
			cout << i << '\n';
			return 0;
		}
	}

	cout << 0 << '\n';
}