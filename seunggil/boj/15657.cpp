#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, numSize;
vector<int> inputData;
int result[8];

void print(int index, int now) {
	if (now == numSize) {
		for (int i = 0; i < numSize; i++) {
			cout << result[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = index; i < n; i++) {
			result[now] = inputData[i];
			print(i, now + 1);
		}
	}
}


int main(void) {
	cin >> n >> numSize;
	
	inputData.resize(n);
	for (int i = 0; i < n; i++)
		cin >> inputData[i];
	sort(inputData.begin(), inputData.end());

	print(0, 0);

	return 0;
}