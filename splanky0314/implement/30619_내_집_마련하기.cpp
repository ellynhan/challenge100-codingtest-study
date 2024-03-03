#include <iostream>
using namespace std;

int main() {
	int n,m,inp,l,r;
	int a[301] = {};
	int arr[301] = {};
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> inp;
		a[inp]=i;
	}
	cin >> m;
	for(int t=0; t<m; t++) {
		for(int i=1; i<=n; i++) {
			arr[i] = a[i];
		}

		cin >> l >> r;
		for(int i=l; i<=r; i++) {
			for(int j=l; j<=r; j++) {
				if(i==j) continue;
				if(i*arr[i]+j*arr[j]<i*arr[j]+j*arr[i]) {
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++){
				if(arr[j]==i) {
					cout << j << " ";
					break;
				}
			}
		}
		cout << "\n";
	}
}