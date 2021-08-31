#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int m, n;
int main() {

	int n; // N
	cin >> n;

	vector<pair<int, int>> result;
	result.reserve(n + 1);
	result.emplace_back(1, 0);
	result.emplace_back(0, 3);

	for (int i = 2; i < n + 1; i++) {
		pair<int, int> b1 = result[i - 2];
		pair<int, int> b2 = result[i - 1];
		int num = (b1.first + b1.second + b2.first * 2 + b2.second) % 9901;
		result.emplace_back(num, 3);
	}

	cout << (result.back().first + result.back().second) % 9901;

	return 0 ;
}
