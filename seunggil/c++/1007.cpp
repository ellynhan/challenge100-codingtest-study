#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

pair<int, int> inputData[20];
int pos;
int neg;
int x;
int y;

double ans;

void findCase(int now, int total) {
	if (now == total) {
		double result1 = x;
		double result2 = y;

		double r = sqrt(abs(result1 * result1) + abs(result2 * result2));

		ans = min(ans, r);

		return;
	}
	if (pos < total / 2) {
		x += inputData[now].first;
		y += inputData[now].second;
		pos++;
		findCase(now + 1, total);
		x -= inputData[now].first;
		y -= inputData[now].second;
		pos--;
	}
	if (neg < total / 2) {
		x -= inputData[now].first;
		y -= inputData[now].second;
		neg++;
		findCase(now + 1, total);
		x += inputData[now].first;
		y += inputData[now].second;
		neg--;
	}
	
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(12);
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		pos = 0;
		neg = 0;
		x = 0;
		y = 0;

		ans = (double)(1 << 31 - 1);

		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			inputData[i] = { a,b };
		}

		findCase(0, n);

		cout << ans << '\n';
	}



	return 0;
}