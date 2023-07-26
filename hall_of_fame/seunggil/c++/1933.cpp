#include <iostream>
#include <utility>
#include <queue>
#include <set>
#include <cmath>
using namespace std;

struct pairSort {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first != b.first)
			return a.first > b.first;
		return abs(a.second) < abs(b.second);
	};
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<pair<int, int>,vector<pair<int,int>>, pairSort> inputData;

	int n;
	cin >> n;

	
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		inputData.emplace(a, b);
		inputData.emplace(c, -b);
	}


	int height = 0;
	multiset<int, greater<int>> skyline;

	while(inputData.size()){
		pair<int, int> iter = inputData.top();

		while(true) {
			inputData.pop();
			if (iter.second > 0)
				skyline.insert(iter.second);
			else
				skyline.erase(skyline.find(-iter.second));

			if (inputData.size() && iter.first == inputData.top().first)
				iter = inputData.top();
			else
				break;
		}

		if (skyline.empty()) {
			height = 0;
			cout << iter.first << ' ' << height << ' ';
		}
		else if (height != *skyline.begin()) {
			height = *skyline.begin();
			cout << iter.first << ' ' << height << ' ';
		}
	}

	return 0;
}