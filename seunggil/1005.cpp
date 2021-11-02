#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class building{
public:
	int preTime = 0;
	int time = 0;
	int count = 0;
	int finishtime = 0;
	unordered_set<int> nextBuilding;
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int n, ruleCount, finish;
		cin >> n >> ruleCount;

		vector<building> inputData(n+1);
		for (int j = 1; j < n+1; j++)
			cin >> inputData[j].time;
		for (int j = 0; j < ruleCount; j++) {
			int a, b;
			cin >> a >> b;
			inputData[b].count++;
			inputData[a].nextBuilding.insert(b);
		}
		inputData[0].count = -1;
		cin >> finish;

		queue<building*> bfs;
		//for (building iter : inputData) {
		//	cout << iter.preTime << ' ' << iter.time << ' ' << iter.count << endl;
		//	for (int iter2 : iter.nextBuilding)
		//		cout << iter2 << ' ';
		//	cout << endl;
		//}
		for (building& iter : inputData) {
			if (!iter.count)
				bfs.push(&iter);
		}
		
		while (bfs.size()) {
			building* iter = bfs.front();
			bfs.pop();
			iter->finishtime = iter->preTime + iter->time;

			for (int nb : iter->nextBuilding) {
				inputData[nb].count--;
				inputData[nb].preTime = max(inputData[nb].preTime, iter->finishtime);

				if (!inputData[nb].count)
					bfs.push(&inputData[nb]);
			}
		}

		cout << inputData[finish].finishtime << '\n';
	}
	

	return 0;
}