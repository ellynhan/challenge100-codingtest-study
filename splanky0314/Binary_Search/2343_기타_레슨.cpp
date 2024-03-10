#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, maxval = -1, sum = 0;
	vector<int> v(100001);
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> v[i];
		if(maxval==-1 || maxval<v[i]) maxval = v[i];
		sum += v[i];
	}

	int l = maxval, r = sum, mid;

	while(l<=r) {
		bool flag = false;
		mid = (l+r)/2;
		int idx = 0, cur = 0;
		//cout << mid;
		for(int i=0; i<m; i++) {
			cur = 0;
			while(1) {
				if(cur+v[idx] <= mid) {
					cur += v[idx];
					idx++;
				}
				else {
					break;
				}

				if(idx == n) {
					//cout << "OK";
					r = mid-1;
					flag = true;
					break;
				}
			}
			if(flag) break;			
		}
		if(!flag) {
			l = mid+1;
		}
		//cout << endl;
		
	}
	cout << l;
}