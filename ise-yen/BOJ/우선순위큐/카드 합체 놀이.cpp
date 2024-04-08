#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n{}, m{};
	long long answer{};
	priority_queue<long long> pq;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long card{};
		cin >> card;
		pq.push(-card);
		answer += card;
	}

	for (int i = 0; i < m; i++) {
		long long c1 = pq.top();
		pq.pop();
		long long c2 = pq.top();
		pq.pop();

		answer += -c1;
		answer += -c2;
		pq.push(c1 + c2);
		pq.push(c1 + c2);
	}

	cout << answer;

	return 0;
}
