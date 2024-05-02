#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int result{}, N{}, M{};
int memo[100001];

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

	cin >> N >> M;
	vector<pair<int, pair<int, int>>> v; // c, a , b;

	// 초기화
	for (int i = 1; i <= N; i++) {
		memo[i] = i;
	}

	// 입력
	for (int i = 0; i < M; i++) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		v.push_back({ c, {a, b} });
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
