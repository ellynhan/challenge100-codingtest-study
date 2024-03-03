#include <iostream>
using namespace std;

char c[50][50]={};
int n, m;

int search(int x, int y) {
	int cnt1=0, cnt2=0;
	for(int i=x; i<x+8; i++) {
		for(int j=y; j<y+8; j++) {
			if(i%2 == j%2) {
				if(c[i][j]=='B') cnt2++;
				else cnt1++;
			}
			else {
				if(c[i][j]=='W') cnt2++;
				else cnt1++;
			}
		}
	}
	return (cnt1<=cnt2 ? cnt1:cnt2);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    

	char tmp;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> c[i][j];
		}
	}

	int min=500, result;
	for(int i=0; i<=n-8; i++) {
		for(int j=0; j<=m-8; j++) {
			result = search(i,j);
			if(result<min) min = result;
		}
	}
	cout << min;
}