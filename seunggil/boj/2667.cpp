#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;


int n;

const int x[] = { 1, -1, 0,  0 };
const int y[] = { 0,  0, 1, -1 };

bool checkPos(const pair<int, int> pos, const vector<vector<int>>& map) {
	if(pos.first < 0 || pos.first >= n)
		return false;
	if (pos.second < 0 || pos.second >= n)
		return false;

	return map[pos.first][pos.second];
}

int main(void) {
	
	cin >> n;
	vector<vector<int>> inputData(n, vector<int>(n));
	stack<pair<int, int>> apart;
	for (int i = 0; i < n; i++) {
		string ins;
		cin >> ins;
		for (int j = 0; j < n; j++)
			inputData[i][j] = ins[j] - '0';
	}
		
			

	vector<int> answers;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {

			int answer = 0;
			if (inputData[i][j]) {
				answer++;
				inputData[i][j] = 0;
				for (int k = 0; k < 4; k++)
					apart.push(make_pair(i + x[k], j + y[k]));
			}
				
			while (apart.size()) {
				const pair<int, int> pos = apart.top();
				apart.pop();

				if (checkPos(pos, inputData)) {
					answer++;
					inputData[pos.first][pos.second] = 0;
					for (int k = 0; k < 4; k++)
						apart.push(make_pair(pos.first + x[k], pos.second + y[k]));
				}
			}
			if (answer)
				answers.push_back(answer);
		}

	cout << answers.size() << endl;

	sort(answers.begin(), answers.end());
	for (int iter : answers)
		cout << iter << endl;

	return 0;
}