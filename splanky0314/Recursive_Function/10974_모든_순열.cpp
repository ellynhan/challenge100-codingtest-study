#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int arr[10];
bool v[10];

void solve(int cnt) {
	if(cnt>n) {
		for(int i=1; i<=n; i++) {
			cout << arr[i] << " ";
		} cout << "\n";
	}
	
	for(int i=1; i<=n; i++) {
		if(!v[i]) {
			arr[cnt] = i;
			v[i] = 1;
			solve(cnt+1);
			arr[cnt] = 0;
			v[i] = 0;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	solve(1);
}