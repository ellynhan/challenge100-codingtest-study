#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 100001;
int N{}, M{};
int memo[MAX];

vector < pair<int, pair<int, int>>> edges;
int result;

// 집합 찾기
int Find(int v) {
	if (v == memo[v]) return v;
	else return memo[v] = Find(memo[v]);
}

// 집합 만들기
void UnionV(int a, int b, int c) {
	a = Find(a);
	b = Find(b);
	if (a != b) result += c;
	if (a < b) memo[b] = a;
	else memo[a] = b;
}

// 초기화
void Initial() {
	// 메모이제이션용 메모를 자기 자신으로 초기화
	for (int i = 1; i <= N; i++) {
		memo[i] = i;
	}
}

// 간선 정보 입력
void Input() {
	for (int i = 0; i < M; i++) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		edges.push_back({ c, {a, b} });
	}
}

// 크루스칼 알고리즘
void Kruskal() {
	// 정렬
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		int c = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		// 집합화
		UnionV(a, b, c);
	}
}

int main() {
	cin.tie();
	ios::sync_with_stdio(false);
	cin >> N >> M;
	Initial();
	Input();
	Kruskal();
	cout << result;
	return 0;
}
