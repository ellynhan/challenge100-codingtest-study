#include <iostream>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

int me, brother;
unordered_map<int, int> map; // 위치, 최소 도달 시간
int answer = -1;
bool checkValid(pair<int, int> pos) {
	if (pos.first < 0 || pos.first >= 200001 || pos.first >= brother * 2 + 1)
		return false;
	if (map.count(pos.first) && map[pos.first] <= pos.second)
		return false;

	if (answer != -1 && pos.second > answer)
		return false;

	map[pos.first] = pos.second;
	return true;
}

int main(void) {
	
	cin >> me >> brother;
	if (brother <= me) {
		cout << me - brother;
		return 0;
	}

	 
	queue<pair<int, int>> bfs; // 위치, 시간

	bfs.push({ me,0 });

	while (bfs.size()) {
		pair<int, int> now = bfs.front();
		bfs.pop();

		if (!checkValid(now))
			continue;

		if (now.first == brother) {
			answer = now.second;
			continue;
		}

		bfs.push({ now.first + 1, now.second + 1 });
		bfs.push({ now.first - 1, now.second + 1 });
		bfs.push({ now.first * 2, now.second });

	}

	cout << answer;

	return 0;

}