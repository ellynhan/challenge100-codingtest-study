#include <iostream>
#include <vector>

using namespace std;

int m, n;
int main() {

	int n, m;
	cin >> n >> m;
	vector<int> inputData(n);
	vector<int> result(10001,-1);


	for (int i = 0; i < n; i++) {
		cin >> inputData[i];
		result[inputData[i]] = 1;
	}	

	for (int i = 1; i < m + 1; i++) {
		for (const auto iter : inputData) {
			if ((i - iter > 0) && result[i - iter] != -1) {
				if (result[i] == -1)
					result[i] = result[i - iter] + 1;
				else
					result[i] = (result[i] < result[i - iter] + 1) ? result[i] : result[i - iter] + 1;
			}

		}
	}
	cout << result[m];

	return 0 ;
}