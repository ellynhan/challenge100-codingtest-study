#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;

	cin >> n >> m;

	vector<string> inputData(n);
	unordered_map<string, int> counter;


	for (size_t i = 0; i < n; i++){
		cin >> inputData[i];
		counter[inputData[i]]++;
	}

	cin >> k;

	for (unordered_map<string, int>::iterator iter = counter.begin(); iter != counter.end(); ){
		int zeroCount = 0;
		for (char c : iter->first) {
			if (c == '0')
				zeroCount++;
		}

		if (k % 2 != zeroCount % 2 || zeroCount > k) {
			iter = counter.erase(iter);
		}
		else {
			iter++;
		}

	}

	int answer = 0;
	for (auto iter : counter) {
		answer = max(answer, iter.second);
	}
	
	cout << answer;

	return 0;
}