#include <iostream>
#include <vector>
#include <stack>
#include <utility>

// https://shaded-elephant-6e3.notion.site/9663-N-Queen-feb9817a80cc455fa79f0ba3a34c57a9
using namespace std;

int n;
int ans = 0;


// 각 선에 체스 있는지 여부
bool leftDiag[27] = {};
bool top[14] = {};
bool rightDiag[27] = {};


void dfs(int x, int y) {
	if (x == n - 1) {
		
		ans++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!(leftDiag[x + 1 - i + n - 1] || top[i] || rightDiag[x + 1 + i])) {
			leftDiag[x + 1 - i + n - 1] = true;
			top[i] = true;
			rightDiag[x + 1 + i] = true;

			dfs(x + 1, i);

			leftDiag[x + 1 - i + n - 1] = false;
			top[i] = false;
			rightDiag[x + 1 + i] = false;
		}

		
	}

}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;


	for (int i = 0; i < n; i++) {
		leftDiag[-i + n - 1] = true;
		top[i] = true;
		rightDiag[i] = true;
		dfs(0, i);

		leftDiag[-i + n - 1] = false;
		top[i] = false;
		rightDiag[i] = false;

	}


	cout << ans;
	return 0;
}