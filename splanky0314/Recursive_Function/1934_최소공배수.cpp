#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,a,b;
	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> a >> b;
		if(b>a) {
			int tmp = a;
			a = b;
			b = tmp;
		}
		cout << a*b/gcd(a,b) << "\n";
	}
}