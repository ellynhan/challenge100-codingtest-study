#include <iostream>
#include <vector>

using namespace std;

#define infinite 160000

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int area, length, road;
	cin >> area >> length >> road;

	vector<int> item(area);
	vector<vector<int>> inputData(area, vector<int>(area, infinite));

	for (int i = 0; i < area; i++){
		cin >> item[i];
		inputData[i][i] = 0;
	}

	for (int i = 0; i < road; i++){
		int from, to, len;
		cin >> from >> to >> len;

		inputData[from - 1][to - 1] = len;
		inputData[to - 1][from - 1] = len;
	}
	

	for (int i = 0; i < area; i++)
		for (int j = 0; j < area; j++)
			for (int z = 0; z < area; z++)
				inputData[j][z] = min(inputData[j][z], inputData[j][i] + inputData[i][z]);

	int answer = 0;
	for (int i = 0; i < area; i++) {
		int ans = 0;

		for (int j = 0; j < area; j++) {
			if (inputData[i][j] <= length)
				ans += item[j];
		}
		answer = max(answer, ans);
	}

	cout << answer;

	return 0;
}