#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	queue<int> q;
	cin >> n;
	for(int i=1; i<=n; i++) {
		q.push(i);
	}

	int i = 1;
	while(q.size()!=1) {
		if(i%2) {
			q.pop();
		}
		else {
			int tmp = q.front();
			q.push(tmp);	
			q.pop();
		}
		i++;
	}
	cout << q.front();
}