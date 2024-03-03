#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool arr[101][101] = {};
	int t,a,b;
	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> a >> b;
		for(int k=a; k<a+10; k++) {
			for(int j=b; j<b+10; j++) {
				arr[k][j] = 1;
			}
		}
	}

	int cnt = 0;
	for(int i=1; i<=100; i++) {
		for(int j=1; j<=100; j++) {
			cnt+=arr[i][j];
		}
	}
	cout << cnt;
}