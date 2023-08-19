//1114 ~ 1132
#include <iostream>
#include <queue>
using namespace std;

int N, M; //세로 가로

int box[1001][1001];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int main() {
	int maxday = 0;
	int count = 0;
	queue<pair<pair<int,int>, int>> q;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({ {i,j},0 });
				box[i][j] = -1;
				count += 1;
			}
			else if (box[i][j] == -1) {
				count += 1;
			}
		}
	}
	while (!q.empty()) {
		int day = q.front().second;
		int y = q.front().first.first;
		int x = q.front().first.second;
		q.pop();
		if (maxday < day) maxday = day;
		for (int i = 0; i < 4; i++) {
			int Y = y + dy[i];
			int X = x + dx[i];
			if (Y >= N || X >= M || Y < 0 || X < 0)continue;
			if (box[Y][X] == 0) {
				count += 1;
				box[Y][X] = -1;
				q.push({ {Y,X}, day + 1 });
			}
			
		}
	}

	if (M*N == count) {
		cout << maxday;
	}
	else {
		cout << -1;
	}
}