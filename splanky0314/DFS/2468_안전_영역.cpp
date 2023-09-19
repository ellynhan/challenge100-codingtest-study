#include <iostream>
using namespace std;
using ll = long long;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool v[101][101];
int arr[101][101];
int n;

void dfs(int x, int y, int tar) {
	v[x][y]=1;
	for(int k=0; k<4; k++) {
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(0<=nx&&ny<n && 0<=ny&&ny<n && !v[nx][ny] && arr[nx][ny]>tar) {
			dfs(nx,ny,tar);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int max=0;
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}

	for(int p=0; p<=100; p++) {
		int cnt=0;
		fill(&v[0][0], &v[100][100], 0);
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(!v[i][j] && arr[i][j]>p) {
					dfs(i,j,p);
					cnt++;
				}
			}
		}
		if(max<cnt) {
			max=cnt;
		}
	}
	cout << max;
}