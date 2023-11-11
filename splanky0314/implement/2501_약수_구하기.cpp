#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,k;
	cin >> n >> k;
	int num = 1;
	while(k>0) {
		if(n<num) {
			cout << 0;
			return 0;
		}

		if(n%num==0) {
			k--;
		}
		num++;
	}
	cout << num-1;
}