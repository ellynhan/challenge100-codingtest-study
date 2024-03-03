#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int arr[1500][1500];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, cnt=0, ans;
	cin >> n;
	vector<int> ptr(n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}
	for(int i=0; i<n; i++) {
		ptr[i] = n-1;
	}

	while(cnt<n) {
		int max = 0;
		for(int i=1; i<n; i++) {
			if(arr[ptr[i]][i]>arr[ptr[max]][max]) max = i;
		}
		ans = arr[ptr[max]][max];
		ptr[max]--;
		cnt++;
	}

	cout << ans;
}