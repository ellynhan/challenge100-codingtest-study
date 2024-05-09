#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 1001;
int memo[MAX];
unsigned long long result{};

int Find(int n) {
	if (memo[n] == n) return n;
	else return memo[n] = Find(memo[n]);
}

void Union(int a, int b, int c) {
	a = Find(a);
	b = Find(b);
	if (a != b) result += c;
	if (a < b) memo[b] = a;
	else memo[a] = b;
}

int main() {
	cin.tie();
	ios::sync_with_stdio(false);

	int N{};
	cin >> N;
	for (int i = 1; i <= N; i++) {
		memo[i] = i;
	}
	vector<int> tmp(N + 1);
	vector<vector<int>> map(N + 1, tmp);

	vector<pair<int, pair<int, int>>> v;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (j > i) {
				v.push_back({map[i][j], {i, j}});
			}
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int c = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;
		Union(a, b, c);
	}

	cout << result;

	return 0;
}
