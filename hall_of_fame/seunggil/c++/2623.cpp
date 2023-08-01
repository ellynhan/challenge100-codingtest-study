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
		int singer;
		cin >> singer;
		vector<int> sings;
		for (size_t j = 0; j < singer; j++){
			int s;
			cin >> s;
			sings.push_back(s);
		}

		for (size_t i = 0; i < sings.size()-1; i++){
			inputData[sings[i]].next.push_back(sings[i+1]);
			inputData[sings[i + 1]].entry++;
		}
	}

	queue<int> bfs;

	for (size_t i = 1; i <= n; i++) {
		if (inputData[i].entry == 0)
			bfs.push(i);
	}

	vector<int> ans;

	while (bfs.size()) {
		int now = bfs.front();
		bfs.pop();
		ans.push_back(now);

		for (int n : inputData[now].next) {
			inputData[n].entry--;
			if (inputData[n].entry == 0) {
				bfs.push(n);
			}
		}
	}

	if (ans.size() == n) {
		for(int i : ans){
			cout << i << '\n';
		}
	}
	else {
		cout << 0;
	}

	return 0;
}