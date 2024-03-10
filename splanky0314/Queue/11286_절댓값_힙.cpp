#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

struct compare {
	bool operator() (int a, int b) {
		if(abs(a)==abs(b)) {
			return a > b;
		}
		else {
			return abs(a) > abs(b);
		}
	}
};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	priority_queue<int, vector<int>, compare> pq;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		if(x==0) {
			if(pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}		
		}
		else {
			pq.push(x);
		}
	}
}