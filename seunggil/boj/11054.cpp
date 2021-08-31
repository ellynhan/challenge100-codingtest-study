#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> left(n, { 0,1 }); // num, count
	for (int i = 0; i < n; i++)
		cin >> left[i].first;
	
	vector<pair<int, int>> right(left.begin(), left.end());

	// 증가 수열 찾기
	for (int i = 0; i < n; i++) {
		int num = left[i].first;
		int& count = left[i].second;

		for (int j = i - 1; j >= 0; j--) {
			if (left[j].first < num && left[j].second >= count)
				count = left[j].second + 1;
		}
	}

	//감소 수열 찾기
	for (int i = n-1; i >= 0; i--) {
		int num = right[i].first;
		int& count = right[i].second;

		for (int j = i + 1; j < n; j++) {
			if (right[j].first < num && right[j].second >= count)
				count = right[j].second + 1;
		}
	}

	int answer = 0;

	for (int i = 0; i < n; i++) {
		int cand = left[i].second + right[i].second - 1;
		if (answer < cand)
			answer = cand;
	}

	cout << answer;

	return 0;
}