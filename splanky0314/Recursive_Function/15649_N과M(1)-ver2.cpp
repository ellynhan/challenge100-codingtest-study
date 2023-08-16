#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr(10), used(10);

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
            if(!used[i]) {
                used[i]=1;
                arr[x]=i;
                solve(x+1);
                used[i]=0;
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