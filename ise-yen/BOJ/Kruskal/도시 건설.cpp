#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 100001;
int N{}, M{};
long long cost{};
int memo[MAX]{};

int Find(int n) {
	if (n == memo[n]) return n;
	else return memo[n] = Find(memo[n]);
}

void Union(int a, int b, int c) {
	a = Find(a);
	b = Find(b);
	
	if (a != b) cost += c;
	if (a < b) memo[b] = a;
	else memo[a] = b;
}



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		memo[i] = i;
	}

	long long sum{};
	vector<pair<int, pair<int, int>>> v;

	for (int i = 0; i < M; i++) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		sum += c;
		v.push_back({ c, {a, b} });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int c = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;
		Union(a, b, c);
	}

	bool isSame = true;
	for (int i = 1; i < N; i++) {
		if (Find(i) != Find(i + 1)) {
			isSame = false;
			break;
		}
	}
	if (isSame) cout << sum - cost;
	else cout << -1;

	return 0;
}
