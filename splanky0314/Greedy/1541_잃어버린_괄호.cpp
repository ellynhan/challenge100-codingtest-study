#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	ll sum = 0;
	int fir = 0;
	int idx = 0;
	bool minus = false;
	vector<int> v(50);
	cin >> s;
	for(int i=0; i<s.size(); i++) {
		if('0'<=s[i] && s[i]<='9') {
			v[idx] = v[idx]*10 + int(s[i]) - '0';
		}
		else if(s[i]=='-') {
			if(minus) {
				v[idx] *= -1;
			}
			minus = true;
			if(i!=0) {
				idx++;
			}
		}
		else if(s[i]=='+') {
			if(minus) {
				v[idx] *= -1;
			}
			minus = false;
			idx++;
		}
	}
	if(minus) {
		v[idx] *= -1;
	}

	ll cur = 0;
	for(int i=idx; i>=0; i--) {
		if(v[i]>=0) {
			cur += v[i];
		}
		else {
			sum -= cur+ (-1)*v[i];
			cur = 0;
		}
	}
	sum += cur;
	cout << sum;

	// for(int i=0; i<v.size(); i++) {
	// 	cout << v[i] << " ";
	// }
}