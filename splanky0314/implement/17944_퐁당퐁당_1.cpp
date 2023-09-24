#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	long long n,t,cnt=0;
	bool flag=0;
	cin >> n >> t;
	for(int i=0; i<t; i++) {
		if(cnt==1 && flag) {
			flag=0;
			cnt++;
		}
		else if(cnt>=2*n || flag) {
			flag=1;
			cnt--;
		}
		else {
			cnt++;
		}
	}

	cout << cnt;
}