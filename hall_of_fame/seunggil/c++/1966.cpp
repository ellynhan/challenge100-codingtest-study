#include <cstdio>
#include <utility>
#include <queue>
#include <set>

using namespace std;

int main(void) {
	int test_case;
	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++) {
		queue<pair<int, int>> printerQueue;
		multiset<int> priority;
		int docuCount, index;
		scanf("%d %d", &docuCount, &index);
		for (int j = 0; j < docuCount; j++) {
			int pri;
			scanf("%d", &pri);
			printerQueue.emplace(j, pri);
			priority.insert(pri);
		}


		while (printerQueue.size()) {
			pair<int, int> front = printerQueue.front();
			printerQueue.pop();

			if (*(--priority.end()) == front.second){
				priority.erase(--priority.end());

				if (index == front.first) {
					printf("%d\n", docuCount - printerQueue.size());
					break;
				}
			}
			else
				printerQueue.push(front);
		}
	}
	return 0;
}