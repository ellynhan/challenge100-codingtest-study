#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> inputData;
vector<bool> used;
vector<int> result;
void backTracking(int now, int count) {
	if (count == M) {
		for (int iter : result)
			printf("%d ", iter);
		printf("\n");
	}
	else {
		for (int i = 0; i < inputData.size(); i++) {
			if (!used[i]) {
				result[count] = inputData[i];
				used[i] = true;
				backTracking(i, count + 1);
				used[i] = false;
			}
		}
	}
}


int main(void) {
	scanf("%d %d", &N, &M);
	inputData = vector<int>(N);
	used = vector<bool>(N);
	result = vector<int>(M);

	for (int i = 0; i < N; i++)
		scanf("%d", &inputData[i]);
	
	sort(inputData.begin(), inputData.end());
	backTracking(0, 0);

	return 0;
}