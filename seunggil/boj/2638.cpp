#include <vector>
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

vector<vector<int>> inputData;
int row, column;

bool checkValid(pair<int,int> p) {
	if (p.first < 0 || p.first >= row)
		return false;
	if (p.second < 0 || p.second >= column)
		return false;

	return inputData[p.first][p.second] != -2;
}

int main(void) {
	cin >> row >> column;

	inputData = vector<vector<int>>(row, vector<int>(column));
	stack<pair<int, int>> dfs;
	int cheeze = 0;
	int time = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++) {
			int in;
			cin >> in;
			// 없는 부분은 -1, 있는 부분은 0으로 저장
			// 이후 dfs에서 방문한 지역은 -2로, 치즈 있는 곳은 공기가 접촉할때마다 +1 => 2되면 그 치즈는 녹는것.
			if (in == 0)
				inputData[i][j] = -1;
			else {
				inputData[i][j] = 0;
				cheeze++;
			}
		}


	while (cheeze) {
		// 가장자리에는 치즈가 놓이지 않으므로 air에서 접근이 됨.
		for (int i = 0; i < row; i++) {
			if (i == 0 || i == row - 1) {
				for (int j = 0; j < column; j++)
					dfs.push({ i,j });
			}
			else {
				dfs.push({ i,0 });
				dfs.push({ i,column - 1 });
			}

		}

		while (!dfs.empty()) {
			pair<int, int> pos = dfs.top();
			dfs.pop();

			if (!checkValid(pos))
				continue;

			// 치즈면 +1하고 넘어감
			if (inputData[pos.first][pos.second] >= 0) {
				inputData[pos.first][pos.second]++;
				continue;
			}
			// 공기면 -2로
			inputData[pos.first][pos.second] = -2;
			dfs.push({ pos.first + 1,pos.second });
			dfs.push({ pos.first - 1,pos.second });
			dfs.push({ pos.first	,pos.second + 1 });
			dfs.push({ pos.first	,pos.second - 1 });
		}

		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++) {
				if (inputData[i][j] >= 2) { // 녹는 치즈
					inputData[i][j] = -1;
					cheeze--;
				}
				else if (inputData[i][j] >= 0) { // 안녹을 치즈
					inputData[i][j] = 0;
				}
				else if(inputData[i][j] < -1) {
					inputData[i][j] = -1;
				}
			}
		//for (int i = 0; i < row; i++) {
		//	for (int j = 0; j < column; j++)
		//		cout << inputData[i][j] << " ";
		//	cout << endl;
		//}

		time++;
	}
	
	cout << time;
	return 0;

}