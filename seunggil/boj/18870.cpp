#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;

	cin >> n;

	vector<int> inputData(n);
	map<int, int> coordinateLine;

	for (int i = 0; i < n; i++) {
		cin >> inputData[i];
		coordinateLine.insert({ inputData[i] ,0 });
	}

	int zippedNumber = 0;
	for (pair<const int, int>& cordIter : coordinateLine) {
		cordIter.second = zippedNumber;
		zippedNumber++;
	}


	for (const int inputDataIter : inputData)
		cout << coordinateLine[inputDataIter] << " ";

	return 0;
}