#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr(10);
void f(int x) {
    if(x==m) {
        for(int i=0; i<m; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    else if(x==0) {
        for(int i=1; i<=n; i++) {
            arr[x] = i;
            f(x+1);
        }
    }
    else {
        for(int i=arr[x-1]+1; i<=n; i++) {
            arr[x] = i;
            f(x+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> n >> m;
    f(0);
}