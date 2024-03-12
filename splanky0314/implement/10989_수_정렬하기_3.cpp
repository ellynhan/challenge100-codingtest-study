#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int cnt[10001] = {};
	int tmp = 0;

	for(int i=0; i<n; i++) {
		cin >> tmp;
		cnt[tmp]++;
	}

	for(int i=0; i<=10000; i++) {
		while(cnt[i]>0) {
			cout << i << "\n";
			cnt[i]--;
		}
	}
}