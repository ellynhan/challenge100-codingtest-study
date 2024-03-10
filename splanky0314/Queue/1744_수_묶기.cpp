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

	int n, tmp;
	int cnt0;
	priority_queue<int, vector<int>> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		if(tmp>0) pq1.push(tmp);
		else if(tmp==0) cnt0++;
		else pq2.push(tmp);
	}

	// for(int i=0; i<n; i++) {
	// 	cout << pq2.top() << " ";
	// 	pq2.pop();
	// }

	int a, b;
	ll sum = 0;
	while(pq1.size()>1) {
		a = pq1.top();
		pq1.pop();
		b = pq1.top();
		pq1.pop();
		if(a==1 || b==1) {
			sum += a+b;
		}
		else sum += a*b;
	}
	if(!pq1.empty()) {
		sum += pq1.top();
		pq1.pop();
	}

	while(pq2.size()>1) {
		a = pq2.top();
		pq2.pop();
		b = pq2.top();
		pq2.pop();
		sum += a*b;
	}
	if(!pq2.empty()) {
		if(cnt0 == 0) {
			sum += pq2.top();
			pq2.pop();
		}
	}

	cout << sum;
}