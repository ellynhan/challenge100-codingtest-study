#include <iostream>
#include <list>
#include <utility>

using namespace std;

void print(const list<pair<int, int>> &result) {
	for (const pair<int, int>& iter : result) {
		cout << iter.first << " : " << iter.second << endl;
	}
}
int main(void) {
	int N;
	int answer = 0;
	list<pair<int, int>> result;
	
	cin >> N;
	
	for (int i = 1; i < N + 1; i++) {
		bool add = false;
		int day, reward;
		cin >> day >> reward;
		if (i + day - 1 < N + 1) {
			for (pair<int, int>& iter : result)
				if (iter.first < i) {
					add = true;
					result.emplace_front(iter.first, iter.second);
					iter.first = i + day - 1;
					iter.second += reward;

					if (answer < iter.second)
						answer = iter.second;
				}
			if (!add) {
				result.emplace_back(i + day - 1, reward);
				if (answer < result.back().second)
					answer = result.back().second;
			}

			//print(result);
			//cout << endl << endl;
		}
		
		
	}

	//print(result);

	cout << answer << endl;
	return 0;
}