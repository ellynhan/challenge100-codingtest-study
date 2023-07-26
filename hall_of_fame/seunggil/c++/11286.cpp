#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct oper {
public:
	bool operator()(int a, int b) {
		if (abs(a) != abs(b))
			return abs(a) > abs(b);
		else
			return a > b;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, oper> absQueue;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int order;
		cin >> order;

		if (order == 0) {
			if (absQueue.size()) {
				cout << absQueue.top() << '\n';
				absQueue.pop();
			}
			else
				cout << 0 << '\n';
			
		}
		else {
			absQueue.push(order);
		}
	}


	return 0;
}