#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	vector<vector<int>> inputData;
	int n, count;

	scanf("%d %d", &n, &count);
	inputData = vector<vector<int>>(n+1, vector<int>(n+1));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int n;
			scanf("%d", &n);
			inputData[i][j] = n + inputData[i][j - 1] + inputData[i - 1][j] - inputData[i - 1][j - 1];
		}
	
	for (int i = 0; i < count; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		int result = inputData[c][d] - inputData[c][b - 1] - inputData[a - 1][d] + inputData[a - 1][b - 1];

		printf("%d\n", result);
	}

	return 0;
}