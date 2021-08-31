#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	string inputData;

	cin >> N >> M >> inputData;


	
	const int patternSize = 3 + 2 * (N - 1);
	int answer = 0;
	int subStrSize = 0;
	bool preIsI = false;

	for (int i = 0; i < M; i++) {
		if (inputData[i] == 'I') {
			if (preIsI) {
				if (subStrSize >= patternSize)
					answer += 1 + (subStrSize - patternSize) / 2;
				subStrSize = 1;
			}
			else {
				subStrSize++;
			}
			preIsI = true;
		}
		else {
			if (preIsI) {
				subStrSize++;
			}
			else {
				subStrSize--;
				if (subStrSize >= patternSize)
					answer += 1 + (subStrSize - patternSize) / 2;
				subStrSize = 0;
			}
			preIsI = false;
		}
	}

	if (inputData[M-1] == 'O')
		subStrSize--;

	if (subStrSize >= patternSize)
		answer += 1 + (subStrSize - patternSize) / 2;
	

	cout << answer;

	return 0;
}