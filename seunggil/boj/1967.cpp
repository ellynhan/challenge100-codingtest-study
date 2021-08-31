#include <iostream>
#include <map>
#include <list>
#include <set>
#include <utility>
#include <vector>

using namespace std;
int main(void) {

	int n;
	cin >> n;
	vector<multiset<int>> result(n + 1, { 0 }); // index 맞추기위해 0번 빈 set 추가
	map<int, list<pair<int, int>>> inputData;
	
	int parent, child, len;
	int sum = 0;
	for (int i = 0; i < n-1; i++) {
		cin >> parent >> child >> len;
		inputData[parent].push_back({ child,len });
	}

	for (int i = n; i > 0; i--) {
		for (const auto& iter : inputData[i])
			result[i].insert(*(result[iter.first].rbegin()) + iter.second);
		if (result[i].size() > 1) {
			int s = 0;
			auto iter = result[i].rbegin();
			s += *(iter++);
			s += *iter;
			if (s > sum)
				sum = s;
		}
	}

	cout << sum;
	return 0;
}