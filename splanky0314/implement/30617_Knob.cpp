#include <iostream>

using namespace std;

int main() {
	int t, l, r, ls = 10, rs=10, ans=0;
	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> l >> r;
		if(ls == l && l!=0) ans++;
		if(rs == r && r!=0) ans++;
		if(l==r && l!=0) ans++;
		rs = r;
		ls = l;
	}
	cout << ans;
}