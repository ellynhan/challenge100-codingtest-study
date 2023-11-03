#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool v[101][101];
int n,m,k;

int dfs(int x, int y) {
	v[x][y] = 1;
	ll sum = 1;
	for(int p=0; p<4; p++) {
		int nx = x+dx[p];
		int ny = y+dy[p];
		if(0<=nx && nx<n && 0<=ny && ny<m && !v[nx][ny]) {
			sum += dfs(nx, ny);
		}
	}
	return sum;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a,b,c,d;
	cin >> n >> m >> k;
	for(int t=0; t<k; t++) {
		cin >> a >> b >> c >> d;
		for(int j=a; j<c; j++) {
			for(int i=b; i<d; i++) {
				v[i][j] = 1;
			}
		}
	}
	int cnt=0;
	vector<int> arr;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!v[i][j]) {
				arr.push_back(dfs(i,j));
				cnt++;
			}
		}
	}
	sort(arr.begin(), arr.end());
	cout << cnt << "\n";
	for(int i=0; i<arr.size(); i++) {
		cout << arr[i] << " ";
	}
}