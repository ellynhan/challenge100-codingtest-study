#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;
class student {
public:
	int parentCount = 0;
	list<int> children;
};
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int stdCount, m;

	cin >> stdCount >> m;

	vector<student> inputData(stdCount + 1);

	for (int i = m - 1; i >= 0; i--){
		int small, big;
		cin >> small >> big;
		inputData[small].parentCount += 1;
		inputData[big].children.push_back(small);

	}
	
	queue<int> bfs;

	for (int i = 1; i <= stdCount; i++) {
		if (inputData[i].parentCount == 0)
			bfs.push(i);
	}

	vector<int> answer;
	answer.reserve(stdCount);

	while (bfs.size()) {
		int now = bfs.front();
		bfs.pop();
		answer.push_back(now);

		for (int iter : inputData[now].children) {
			inputData[iter].parentCount--;
			if (inputData[iter].parentCount == 0)
				bfs.push(iter);
		}
		
	}

	for (int i = stdCount - 1; i >= 0; i--) {
		cout << answer[i] << ' ';
	}

	return 0;
}