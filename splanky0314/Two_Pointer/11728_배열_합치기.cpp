#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> a;
	vector<int> b;
	vector<int> ans;
	int n,m, tmp;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}

	for(int i=0; i<m; i++) {
		cin >> tmp;
		b.push_back(tmp);
	}

	int fir=0, sec=0;
	while(ans.size()!=n+m) {
		if(fir>=a.size()) {
			ans.push_back(b[sec]);
			sec++;
		}
		else if(sec>=b.size()) {
			ans.push_back(a[fir]);
			fir++;
		}
		else {
			if(a[fir]<b[sec]) {
				ans.push_back(a[fir]);
				fir++;
			}
			else {
				ans.push_back(b[sec]);
				sec++;
			}
		}
	}

	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " ";
	}
}