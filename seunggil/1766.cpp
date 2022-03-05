#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Node {
public:
	vector<int> next;
	int entry = 0;
};


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	vector<Node> inputData(n+1);
	
	for (size_t i = 1; i <= m; i++){
		int before, after;
		cin >> before >> after;

		inputData[before].next.push_back(after);
		inputData[after].entry++;
	}

	priority_queue<int, vector<int>,greater<int>> pq;

	for (size_t i = 1; i <= n; i++) {
		if (inputData[i].entry == 0)
			pq.push(i);
	}

	while (pq.size()) {
		int now = pq.top();
		pq.pop();
		cout << now << ' ';

		for (int n : inputData[now].next) {
			inputData[n].entry--;
			if (inputData[n].entry == 0) {
				pq.push(n);
			}
		}
	}

	return 0;
}