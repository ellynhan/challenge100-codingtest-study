#include <iostream>
#include <vector>
#include <utility>
#include <deque>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l, tmp;
	deque<pair<int,int>> dq;
	cin >> n >> l;

	for(int i=1; i<=n; i++) {
		cin >> tmp;
		if(!dq.empty() && i>l && dq.front().first <= i-l) {
			dq.pop_front();
		}

		while(!dq.empty() && dq.back().second > tmp) {
			dq.pop_back();
		}
		dq.push_back({i, tmp});
		
		cout << dq.front().second << " ";
		// for(deque<pair<int,int>>::iterator it=dq.begin(); it!=dq.end(); it++) {
		// 	cout << it->first << "," << it->second << "  ";
		// }
		// cout << endl << endl;
	}
}