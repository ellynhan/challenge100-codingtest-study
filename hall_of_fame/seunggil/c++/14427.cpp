#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int n;
	cin >> n;

	vector<int> inputData(n+1);
	map<int, set<int>> tree;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		inputData[i] = num;
		tree[num].insert(i);
	}

	int query;
	cin >> query;

	for (int i = 0; i < query; i++) {
		int type;
		cin >> type;

		if (type == 1) {
			int target, value;
			cin >> target >> value;

			tree[inputData[target]].erase(target);
			if (tree[inputData[target]].empty()) {
				tree.erase(inputData[target]);
			}
			inputData[target] = value;
			tree[value].insert(target);
		}
		else {
			cout << *tree.begin()->second.begin() << '\n';
		}

	}

	return 0;
}