#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> inputData;

int white(int i, int j) {
	bool ans = true;
	int result = 0;
	for (int a = i; a < i + 8; a++) {
		for (int b = j; b < j + 8; b++) {
			if (inputData[a][b] != ans)
				result++;
			ans = !ans;
		}
		ans = !ans;
	}
	return result;
}

int black(int i, int j) {
	bool ans = false;
	int result = 0;
	for (int a = i; a < i + 8; a++) {
		for (int b = j; b < j + 8; b++) {
			if (inputData[a][b] != ans)
				result++;
			ans = !ans;
		}
		ans = !ans;
	}
		
	return result;
}

int main(void) {
	int n, m;
	unsigned int answer = -1;
	cin >> n >> m;

	inputData = vector<vector<bool>>(n, vector<bool>(m));
	
	for(int i = 0; i <n; i++)
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			inputData[i][j] = c == 'W' ? true : false;
		}

	for (int i = 0; i+7 < n; i++)
		for (int j = 0; j+7 < m; j++) {
			int result = min(white(i, j), black(i, j));

			if (answer > result)
				answer = result;	
		}

	cout << answer;
	
	return 0;
}