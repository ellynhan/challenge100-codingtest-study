#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<vector<bool>> result(N, vector<bool>(2 * N - 1));

	N /= 3;
	int k = 0;
	while (N != 0) {
		N = N >> 1;
		k++;
	}
	k--;
		
	N = result.size();
	for (int i = 0; i < 5; i++) {
		result[N-1][i] = true;
		if (i % 2 != 0)
			result[N - 2][i] = true;
		if (i == 2)
			result[N - 3][i] = true;
	}

	int width = 5;
	int height = 3;

	while (k--) {
		for (int i = N - 1; i > N - 1 - height; i--) {
			for(int j = 0; j < width; j++){
				result[i][j + width + 1] = result[i][j];
				result[i - height][j + width / 2 + 1] = result[i][j];
			}
		}
		width = width * 2 + 1;
		height *= 2;
	}

	for (auto& iter1 : result) {
		for (bool iter2 : iter1) {
			cout << (iter2 ? '*' : ' ');
		}
		cout << endl;
	}

	return 0;
}