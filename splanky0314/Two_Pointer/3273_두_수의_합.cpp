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

	int n, tmp, x;
	vector<int> v;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> x;

	sort(v.begin(), v.end());
	int fir=0, sec=v.size()-1;
	int cnt = 0;
	while(fir<sec) {
		if(v[fir]+v[sec]==x) {
			//cout << fir << "L" << sec << endl;
			cnt++;
			fir++;
			sec = v.size()-1;
		}
		else if(v[fir]+v[sec]>x) {
			sec--;
		}
		else {
			fir++;
			sec = v.size()-1;
		}
	}
	cout << cnt;
}