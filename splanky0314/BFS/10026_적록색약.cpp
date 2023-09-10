#include <iostream>
#include <vector>
using namespace std;

int n;
bool v1[100][100];
bool v2[100][100];
char arr[100][100];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs1(int x, int y, char c) {
	v1[x][y]=1;
	for(int k=0; k<4; k++) {
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(0<=nx && nx<n && 0<=ny && ny<n && !v1[nx][ny] && arr[nx][ny]==c) {
			dfs1(nx,ny,c);
		}
	}
}

void dfs2(int x, int y, char c) {
	if(c=='R') c='G';
	v2[x][y]=1;
	for(int k=0; k<4; k++) {
		int nx = x+dx[k];
		int ny = y+dy[k];
		char tar=arr[nx][ny];
		if(tar=='R') tar='G';
		if(0<=nx && nx<n && 0<=ny && ny<n && !v2[nx][ny] && tar==c) {
			dfs2(nx,ny,c);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int cnt1=0, cnt2=0;
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!v1[i][j]) {
				cnt1++;
				dfs1(i,j,arr[i][j]);
			}
			if(!v2[i][j]) {
				cnt2++;
				dfs2(i,j,arr[i][j]);
			}
		}
	}

	cout << cnt1 << " " << cnt2;
}