#include <iostream>
#include <vector>

#define maxValue (100 * 100000 + 1)

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int city, bus;

	cin >> city >> bus;
	
	vector<vector<int>> inputData(city, vector<int>(city, maxValue));

	for (int i = 0; i < bus; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		from--;
		to--;

		inputData[from][to] = min(cost, inputData[from][to]);
	}

	for (int i = 0; i < city; i++)
		for (int j = 0; j < city; j++)
			for (int k = 0; k < city; k++)
				inputData[j][k] = min(inputData[j][k], inputData[j][i] + inputData[i][k]);

	for (int i = 0; i < city; i++) {
		for (int j = 0; j < city; j++) {
			if (i == j || inputData[i][j] >= maxValue)
				cout << 0 << ' ';
			else
				cout << inputData[i][j] << ' ';
		}cout << '\n';
	}

	return 0;
}