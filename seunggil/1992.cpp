#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

class pos {
public:
	int x;
	int y;
	int length;
	
	pos(int x, int y, int length) : x(x), y(y), length(length){}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<char>> inputData(n, vector<char>(n));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> inputData[i][j];
	
	stack<pos> dfs;
	dfs.emplace(0, 0, n);

	string answer = "";
	answer.reserve(n * n);

	while (dfs.size()) {
		pos now = dfs.top();
		dfs.pop();
		
		if (now.x < 0) {
			if (now.x == -1)
				answer.push_back(')');
			else if (now.x == -2)
				answer.push_back('(');
			else if (now.x < 0)
				assert(false);

			continue;
		}
		
		// 모두 동일한지 확인
		char value = inputData[now.x][now.y];
		bool result = true;

		for (int i = now.x; i < now.x + now.length; i++)
			for (int j = now.y; j < now.y + now.length; j++)
				if (value != inputData[i][j]) {
					result = false;
					break;
				}

		if (result)
			answer.push_back(value);
		else {
			dfs.emplace(-1, -1, n); // )
			dfs.emplace(now.x + (now.length / 2), now.y + (now.length / 2)	, now.length / 2);
			dfs.emplace(now.x + (now.length / 2), now.y						, now.length / 2);
			dfs.emplace(now.x					, now.y + (now.length / 2)	, now.length / 2);
			dfs.emplace(now.x					, now.y						, now.length / 2);
			dfs.emplace(-2, -2, n); // (
		}

	}
	
	cout << answer;

	return 0;
}