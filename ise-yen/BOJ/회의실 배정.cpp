#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N{};
	cin >> N;
	vector<pair<int, int>> v;
	int answer{};

	for (int i = 0; i < N; i++) {
		int s{}, e{};
		cin >> s >> e;
		v.push_back({ e, s });
	}
	sort(v.begin(), v.end());

	int start = v[0].second, end = v[0].first;
	answer++;
	for (int i = 1; i < v.size(); i++) {
		int s = v[i].second;
		int e = v[i].first;

		// 이전 회의 종료 전에 시작이면 패스
		if (s < end) continue;
		else {
			start = s;
			end = e;
			answer++;
		}
	}

	cout << answer;
	return 0;
}
