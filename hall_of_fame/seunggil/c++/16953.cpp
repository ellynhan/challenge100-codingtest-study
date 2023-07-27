#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	int ans = 0;
	cin >> a >> b;

	unordered_map<int, int> visit;
	queue<pair<int, int>> bfs;
	bfs.emplace(a, 0);

	while (bfs.size()) {
		pair<int,int> now = bfs.front();
		bfs.pop();
		if (now.first == b) {
			cout << now.second + 1;
			return 0;
		}

		if (visit.count(now.first) == 0) {
			visit[now.first] = now.second;

			if (now.first <= 1e9) {
				bfs.emplace(now.first * 2, now.second + 1);
			}
			if (now.first <= 1e8) {
				bfs.emplace(now.first * 10 + 1, now.second + 1);
			}
			
		}
	}

	cout << -1;

	return 0;
}