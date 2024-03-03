#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// N이 최대 100,000이므로 삽입 정렬은 시간초과
int main() {
	int N{};
	cin >> N;
	vector<pair<int, pair<int, string>>> v; // 나이, <순서, 이름>
	for (int i = 0; i < N; i++) {
		int age{};
		string name;
		cin >> age >> name;
		v.push_back({ age, {i, name} });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second.second << "\n";
	}
	return 0;
}
