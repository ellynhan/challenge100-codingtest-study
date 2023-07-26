#include <set>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	multiset<int> priorityQueue;

	for (int i = 0; i < testCase; i++) {
		priorityQueue.clear();
		int n;
		cin >> n;

		char ord;
		int num;
		for (int j = 0; j < n; j++) {
			cin >> ord >> num;

			if (ord == 'I')
				priorityQueue.insert(num);
			else if (ord == 'D' && priorityQueue.size()) {
				if (num == 1)
					priorityQueue.erase(--priorityQueue.end());
				else
					priorityQueue.erase(priorityQueue.begin());
			}
		}

		if (priorityQueue.size())
			cout << *(--priorityQueue.end()) << ' ' << *priorityQueue.begin() << '\n';
		else
			cout << "EMPTY" << '\n';
	}

	return 0;
}