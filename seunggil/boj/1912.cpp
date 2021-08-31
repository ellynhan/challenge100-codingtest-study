#include <iostream>
#include <vector>

using namespace std;

int m, n;
int main() {

	int n;
	int maxNum;
	cin >> n;
	vector<int> inputData(n);
	vector<long long>result(n);


	for (int i = 0; i < n; i++)
		cin >> inputData[i];
	
	result[0] = inputData[0];
	maxNum = result[0];

	for (int i = 1; i < n; i++) {
		result[i] = result[i - 1] > 0 ? result[i - 1] + inputData[i] : inputData[i];
		if (maxNum < result[i]) maxNum = result[i];
	}

	cout << maxNum;

	return 0 ;
}