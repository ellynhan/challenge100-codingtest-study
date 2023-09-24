#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

string s[101];
bool v[101][101];
int n,m,mini=10001;

// dfs로 돌리면 시간초과
void dfs(int x, int y, int num) {
	v[x][y]=1;
	if(x==n-1 && y==m-1) {
		if(mini>num) mini = num;
	}
	else {
		for(int k=0; k<4; k++) {
			int nx = x+dx[k];
			int ny = y+dy[k];
			if(0<=nx && nx<n && 0<=ny && ny<m && !v[nx][ny] && s[nx][ny]=='1') {
				dfs(nx,ny,num+1);
			}
		}
	}
	v[x][y]=0; // 이게 핵심
}

int bfs(int x, int y, int num) {
	queue<tuple<int,int,int>> q;
	v[x][y]=1;
	q.push({x,y,num});
	while(!q.empty()) {
		tuple<int,int,int> tar = q.front();
		if(get<0>(tar)==n-1 && get<1>(tar)==m-1) {
			return get<2>(tar);
		}
		q.pop();
		for(int k=0; k<4; k++) {
			int nx = get<0>(tar)+dx[k];
			int ny = get<1>(tar)+dy[k];
			if(0<=nx && nx<n && 0<=ny && ny<m && s[nx][ny]=='1' && !v[nx][ny]) {
				q.push({nx,ny,get<2>(tar)+1});
				v[nx][ny]=1;
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> s[i];
	}

	cout << bfs(0,0,1);
}