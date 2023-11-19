#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int n,m,k;
bool v[51][51];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int x, int y) {
	v[x][y] = 0;
	for(int k=0; k<4; k++) {
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(0<=nx&&nx<n&&0<=ny&&ny<m&&v[nx][ny]){
			dfs(nx,ny);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a,b, t;
	cin >> t;
	for(int p=0; p<t; p++) {
		cin >> m >> n >> k;
		for(int i=0; i<k; i++) {
			cin >> b >> a;
			v[a][b] = 1;
		}	

		int cnt=0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(v[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	
}