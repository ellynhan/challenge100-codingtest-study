#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dx[6] = { 0,-1,0,0,1,0 };
const int dy[6] = { 0,0,1,0,0,-1 };
const int dz[6] = { 1,0,0,-1,0,0 };

class pos {
public:
	int x;
	int y;
	int z;
	pos(int x, int y, int z) : x(x), y(y), z(z) {}
};

int x, y, z;
vector<vector<vector<int>>> inputData;

bool isValid(int a, int b, int c) {
	if (a < 0 || a >= x)
		return false;
	if (b < 0 || b >= y)
		return false;
	if (c < 0 || c >= z)
		return false;

	return inputData[c][b][a] == 0;
}

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	

	cin >> x >> y >> z;

	inputData = vector<vector<vector<int>>>(z, vector<vector<int>>(y, vector<int>(x)));

	for (int i = 0; i < z; i++)
		for (int j = 0; j < y; j++)
			for (int k = 0; k < x; k++)
				cin >> inputData[i][j][k];


	queue<pos> bfs;

	for (int i = 0; i < z; i++)
		for (int j = 0; j < y; j++)
			for (int k = 0; k < x; k++)
				if (inputData[i][j][k] == 1)
					bfs.emplace(k, j, i);

	while (bfs.size()) {
		pos now = bfs.front();
		bfs.pop();

		for (int i = 0; i < 6; i++) {
			int a = now.x + dx[i];
			int b = now.y + dy[i];
			int c = now.z + dz[i];
			if (isValid(a, b, c)) {
				inputData[c][b][a] = inputData[now.z][now.y][now.x] + 1;
				bfs.emplace(a, b, c);
			}
		}

	}

	//for (int i = 0; i < z; i++)
	//	for (int j = 0; j < y; j++) {
	//		for (int k = 0; k < x; k++)
	//			cout << inputData[i][j][k] << ' ';
	//		cout << '\n';
	//	}

	int ans = 0;

	for (int i = 0; i < z; i++)
		for (int j = 0; j < y; j++)
			for (int k = 0; k < x; k++)
				if (inputData[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				else
					ans = max(inputData[i][j][k], ans);

	cout << ans - 1;

	return 0;
}