#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	long n, m, max_n=-1, max_m=-1, tmp;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		if(tmp > max_n) {
			max_n = tmp;
		}
	}

	for(int i=0; i<m; i++) {
		cin >> tmp;
		if(tmp > max_m) {
			max_m = tmp;
		}
	}

	cout << max_n + max_m;
}