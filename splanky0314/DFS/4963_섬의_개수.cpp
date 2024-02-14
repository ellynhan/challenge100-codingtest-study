#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
using ll = long long;

int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {1,0,-1,1,0,-1,1,-1};

int w, h;
bool arr[51][51];
bool v[51][51];

void dfs(int x, int y) {
	v[x][y] = 1;
	
	for(int k=0; k<8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if((0<=nx && nx<h && 0<=ny && ny<w) && !v[nx][ny] && arr[nx][ny]==1) {
			dfs(nx,ny);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	while(1) {
		fill(v[0], v[0]+2601, 0);

		cin >> w >> h;
		
		if(w==0 && h==0) break;
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				cin >> arr[i][j];
			}
		}

		int cnt = 0;
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				if(!v[i][j] && arr[i][j]==1) {
					dfs(i,j);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}
}