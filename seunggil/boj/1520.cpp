#include <iostream>
#include <list>
#include <utility>
#include <vector>

#define pos pair<int,int> 

using namespace std;


int m, n;
vector<vector<int>> inputData;	// 높이
vector<vector<long long>> result; // 경우의 수
vector < vector<bool>> checked; // 방문여부
void go(long long x1, int x2, int y2, list<pair<int, int>> route);


// 디버깅용 전체 출력함수.
//void print() {
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++)
//			cout << result[i][j] << " ";
//		cout << endl;
//	}
//	cout << endl;
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	inputData = vector<vector<int>>(m);
	result = vector<vector<long long>>(m);
	checked = vector<vector<bool>>(m);

	for (int i = 0; i < m; i++) {
		inputData[i] = vector<int>(n);
		result[i] = vector<long long>(n);
		checked[i] = vector<bool>(n);
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> inputData[i][j];

	list<pos> route({ {0,0} });
	go(inputData[0][0], 1, 0, route);
	go(inputData[0][0], 0, 1, route);

	cout << result[0][0];

	return 0;
}


void go(long long preVal, int x, int y, list<pos> route) {
	if (!((x >= 0 && x < m) && (y >= 0 && y < n)))
		return;
	
	
	if (preVal > inputData[x][y]) {
		
		if (result[x][y]) {
			int addCount = result[x][y];
			for (const auto& iter : route)
				result[iter.first][iter.second] += addCount;
			//print();
			return;
		}
		else if (checked[x][y]) { // result[x][y])가 0이하 인데 방문 했다 => 여기는 경우의 수 0이므로 더 들어갈 필요 x
			return;
		}
		else if (x == m - 1 && y == n - 1) {
			result[x][y] = 1;
			checked[x][y] = true;
			int addCount = result[x][y];
			for (const auto& iter : route)
				result[iter.first][iter.second] += addCount;
			//print();
			return;
		}
		else {
			route.emplace_back(x, y);
			checked[x][y] = true;
			go(inputData[x][y], x + 1, y, route);
			go(inputData[x][y], x - 1, y, route);
			go(inputData[x][y], x, y + 1, route);
			go(inputData[x][y], x, y - 1, route);
		}
	}
	return;
}