#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;


int main(void) {
	int friends, relation;
	cin >> friends >> relation;

	vector<vector<int>> inputData(friends, vector<int>(friends, 5000));

	for (int i = 0; i < friends; i++)
		inputData[i][i] = 0;
	

	while (relation--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		inputData[a][b] = 1;
		inputData[b][a] = 1;
	}


	for (int i = 0; i < friends; i++) // node
		for (int j = 0; j < friends; j++)
			for (int k = j+1; k < friends; k++) { 
				int path = min(inputData[j][i] + inputData[i][k], inputData[j][k]);
				inputData[j][k] = path;
				inputData[k][j] = path;
			}

	vector<int> result;
	for (const vector<int>& inDataIter : inputData)
		result.push_back(accumulate(inDataIter.begin(), inDataIter.end(),0));
	
	int index = 0;
	int min = result.front();

	for (int i = 1; i < result.size(); i++)
		if (result[i] < min) {
			index = i;
			min = result[i];
		}
	
	cout << index + 1;

	return 0;
}