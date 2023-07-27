#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> inputData;
int blue = 0;
int white = 0;
void solve(int x, int y, int len) {
	bool compare = inputData[x][y];
	for (int i = x; i < x + len; i++)
		for (int j = y; j < y + len; j++)
			if (compare != inputData[i][j]) {
				solve(x, y, len / 2);
				solve(x + len / 2, y, len / 2);
				solve(x, y + len / 2, len / 2);
				solve(x + len / 2, y + len / 2, len / 2);
				return;
			}
	if (compare)
		blue++;
	else
		white++;
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	inputData = vector<vector<bool>>(n, vector<bool>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			bool in;
			cin >> in;
			inputData[i][j] = in;
		}
	solve(0, 0, n);
	cout << white << '\n' << blue;
	return 0;
}