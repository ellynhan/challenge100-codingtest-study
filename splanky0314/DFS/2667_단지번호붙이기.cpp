#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n;
string s[25];
bool v[25][25];

int dfs(int x, int y) {
	v[x][y] = 1;
	int ret = 1;
	for(int k=0; k<4; k++) {
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(0<=nx && nx<n && 0<=ny && ny<n && !v[nx][ny] && s[nx][ny]=='1')
			ret += dfs(nx, ny);
	}
	return ret;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> n;
	for(int i=0; i<n; i++) cin >> s[i];
	vector<int> ans;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!v[i][j] && s[i][j]=='1')
				ans.push_back(dfs(i,j));
		}
	}
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for(auto x:ans) cout << x << "\n";
}