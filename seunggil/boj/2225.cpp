#include <iostream>
#include <vector>

using namespace std;

int m, n;
int main() {

	int n, count; // N
	cin >> n >> count;
	vector<vector<int>> inputData;
	inputData.reserve(count);

	for (int i = 0; i < count; i++)
		inputData.push_back(vector<int>(n+1,1));

	for (int i = 1; i < inputData.size(); i++)
		for (int j = 1; j < inputData[i].size(); j++) 
			inputData[i][j] = (inputData[i][j - 1] + inputData[i - 1][j]) % 1000000000;


	cout << inputData.back().back();

	return 0 ;
}
