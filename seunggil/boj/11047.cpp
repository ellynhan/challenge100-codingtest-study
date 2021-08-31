#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;
	
	vector<int> inputData(N);
	while (N--)
		cin >> inputData[N];
	
	int answer = 0;

	for (int iter : inputData) {
		answer += K / iter;
		K %= iter;
		if (!K)
			break;
	}
	cout << answer;
	return 0;
}