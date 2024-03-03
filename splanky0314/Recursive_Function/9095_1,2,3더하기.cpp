#include <iostream>
#include <vector>
using namespace std;

int n, cnt;

void f(int x) {
	if(x>3) {
		f(x-3);
	}
	if(x>2) {
		f(x-2);
	}
	if(x>1) {
		f(x-1);
	}
	if(x<=3) {
		cnt++;
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		cnt=0;
		cin >> n;
		f(n);
		cout << cnt << "\n";
	}
}