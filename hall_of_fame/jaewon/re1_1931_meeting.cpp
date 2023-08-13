//1021 ~ 1047

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	else {
		return a.second > b.second;
	}

}
int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back({ start, end });
	}
	sort(v.begin(), v.end(), compare);
	int maxCount = 1;
	int maxStart = v[0].first;
	for (int i = 1; i < N; i++) {
		if (v[i].first > maxStart) {
			maxStart = v[i].first;
			continue;
		}
		if (v[i].second <= maxStart) {
			maxStart = v[i].first;
			maxCount += 1;
		}
	}
	cout << maxCount;
}

//탐색하면서 first가 maxStart보다 뒤에 있으면 이 first로 maxStart를 바꿈
//second가 maxStart와 같거나 작으면 이 first로 maxStart를 바꾸고 maxcount를 올림
