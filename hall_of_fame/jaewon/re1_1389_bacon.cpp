//1100 ~ 1113
#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

int N, M;
unordered_set<int> conn[101];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		conn[a].insert(b);
		conn[b].insert(a);
	}

	//bfs, 사람의 번호는 무조건 1부터 N까지
	int min = 100000;
	int minPerson = 0;
	for (int start = 1; start <= N; start++) {
		queue<pair<int,int>> q;
		int visited[101] = { 0 };
		q.push({start,0});
		visited[start] = 1;
		int sum = 0;
		while (!q.empty()) {
			int curr = q.front().first;
			int dist = q.front().second;
			q.pop();
			sum += dist;
			unordered_set<int>::iterator it;
			for (it = conn[curr].begin(); it != conn[curr].end(); it++) {
				int next = *it;
				if (visited[next] == 0) {
					q.push({ next, dist + 1 });
					visited[next] = 1;
				}
			}
		}
		if (min > sum) {
			min = sum;
			minPerson = start;
		}
	}
	cout << minPerson;
}
//각 노드에서 다른 노드들까지의 거리의 합이 가장 적은 사람을 구하는 프로그램