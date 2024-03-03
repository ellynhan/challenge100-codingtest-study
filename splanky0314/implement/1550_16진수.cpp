#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a;
	ll ans=0, tmp;
	int mul = 1;
	cin >> a;
	for(int i=a.length()-1; i>=0; i--) {
		switch (a[i])
		{
		case 'A':
			tmp = 10;
			break;
		case 'B':
			tmp = 11;
			break;
		case 'C':
			tmp = 12;
			break;
		case 'D':
			tmp = 13;
			break;
		case 'E':
			tmp = 14;
			break;
		case 'F':
			tmp = 15;
			break;
		default:
			tmp = int(a[i])-48;
			break;
		}
		
		ans += mul*tmp;
		mul *= 16;
		
	}
	cout << ans;
}