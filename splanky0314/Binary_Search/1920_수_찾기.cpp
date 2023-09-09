#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;	

int n,m,tmp;
vector<int> a;

int search(int tar) {
	int l = 0, r = n-1;
	while(l<=r) {
		int mid = (l+r)/2;
		if(a[mid]==tar) return 1;
		else if(a[mid]>tar) r = mid-1;
		else if(a[mid]<tar) l = mid+1;
	}
	return 0;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> tmp;
		cout << search(tmp) << "\n";
	}
}