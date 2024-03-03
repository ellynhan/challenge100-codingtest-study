#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int dx[] = {0,1,0,1,2,0,2,1,2};
int dy[] = {0,0,1,1,0,2,1,2,2};
int n;
int ans[3];
vector<vector<int>> v;

void f(pair<int,int> a, int size) {
	int tar = v[a.first][a.second];
	bool flag=1;
	for(int i=a.first; i<a.first+size; i++) {
		for(int j=a.second; j<a.second+size; j++) {
			if(tar!=v[i][j]) {
				flag=0;
				break;
			}
		}
	}
	if(flag) {
		ans[tar+1]++;
		return;
	}

	int interval = size/3;
	for(int i=a.first; i<a.first+size; i+=interval) {
		for(int j=a.second; j<a.second+size; j+=interval) {
			f({i,j}, interval);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	v.resize(n, vector<int>(n));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> v[i][j];
		}
	}
	f({0,0}, n);
	cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
}