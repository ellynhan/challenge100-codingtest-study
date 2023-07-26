#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int n, m, b;
vector<vector<int>> inputData;
int height = 0;
int useTime = ~(1 << 31);

void makeground(int a) {
	int t = 0;
	int block = b;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int size = a - inputData[i][j];
			if (size >= 0)
				t += size;
			else
				t += 2 * (-size);
			block -= size;
	}

	if (useTime > t && block >= 0) {
		useTime = t;
		height = a;
	}
	else if (useTime == t && block >= 0) {
		height = max(height,a);
	}

}
int main(void) {
	int max = 0;
	scanf("%d %d %d", &n, &m, &b);
	inputData = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			scanf("%d", &inputData[i][j]);
			if (max < inputData[i][j])
				max = inputData[i][j];
		}

	for (int i = 0; i <= max; i++)
		makeground(i);

	printf("%d %d", useTime, height);

	return 0;
}