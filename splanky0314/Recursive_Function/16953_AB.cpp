#include <iostream>
#include <vector>
using namespace std;

long long minval=-1;
void f(long long a, long long tar, long long cnt) {
	if(a==tar) {
		if(minval>cnt || minval==-1) minval = cnt;
	}
	else if(a>tar) {
		return;
	}
	else {
		f(a*2, tar, cnt+1);
		f(a*10+1, tar, cnt+1);
	}
} 

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	long long a, b;
	cin >> a >> b;
	f(a,b,1);
	cout << minval;
}