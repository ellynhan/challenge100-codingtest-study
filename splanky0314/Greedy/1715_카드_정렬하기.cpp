#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, tmp, sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> tmp;
		pq.push(tmp);
	}
	
	ll a, b;
	while(pq.size()!=1) {
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		sum += a+b;
		pq.push(a+b);
	}
	cout << sum;
}