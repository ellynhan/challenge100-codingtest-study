#include <iostream>

using namespace std;

int answer = 0;
int n;
void dfs(int number) {
	if (number == n)
		answer++;
	else if (number < n) {
		dfs(number + 1);
		dfs(number + 2);
		dfs(number + 3);
	}

	return;
}


int main(void) {
	int testCase;
	cin >> testCase;

	while (testCase--) {
		answer = 0;
		cin >> n;
		dfs(0);
		cout << answer << '\n';
	}

	return 0;
}