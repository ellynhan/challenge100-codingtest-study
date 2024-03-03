#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr(10);

void solve(int x) {
    int flag=1;
    if(x==m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else {
        for(int i=1; i<=n; i++) {
            for(int j=0; j<x; j++) {
                if(i==arr[j]) {
                    flag = 0;
                    break;
                }
                else {
                    flag = 1;
                }
            }
            if(flag==1) {
                arr[x]=i;
                solve(x+1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> n >> m;
    solve(0);
}