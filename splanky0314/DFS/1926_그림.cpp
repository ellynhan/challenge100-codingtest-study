#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int n, m, maxval=0;
int arr[501][501];
bool v[501][501];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int dfs(int x, int y) {
	int sum=1;
	v[x][y]=1;
	for(int k=0; k<4; k++) {
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(0<=nx && nx<n && 0<=ny && ny<m && !v[nx][ny] && arr[nx][ny]==1) {
			sum+=dfs(nx,ny);
		}
	}
	return sum;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!v[i][j] && arr[i][j]==1) {
				cnt++;
				int tmp = dfs(i,j);
				if(tmp>maxval) maxval = tmp;
			}
		}
	}

	cout << cnt << "\n" << maxval;
}