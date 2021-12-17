#include <iostream>
#include <vector>

using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> inputData(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> inputData[i][j];

	for(int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				inputData[i][j] = max(inputData[i][j], inputData[i][k] + inputData[k][j] - 1);
	
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++)
			cout << inputData[i][j] << ' ';
		cout << endl;
	}

	return 0;
}