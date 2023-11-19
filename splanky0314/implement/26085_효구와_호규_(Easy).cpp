#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int n,m;
int arr[1000][1000];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int cnt1=0, cnt0=0;
    bool case1=1, case2=1;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
			if(arr[i][j]==0) cnt0++;
			else cnt1++; 

            if(case1 || case2) {
                if(arr[i][j]==1) {
                    if(i%2 == j%2) {
                        case1 = 0;
                    }
                } 
                else {
                    if(i%2 == j%2) {
                        case2 = 0;
                    }
                }
            }
		}
	}

	if((n%2 && m%2) || cnt0%2 || cnt1%2 || case1 || case2) {
		cout << -1;
	}
	else {
        cout << 1;
    } 
}