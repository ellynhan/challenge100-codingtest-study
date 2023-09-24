#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[] = {1,2,-1,-2,1,2,-1,-2};
int dy[] = {2,1,2,1,-2,-1,-2,-1};
bool v[301][301];

int l;
int tara, tarb;

long long bfs(long long x, long long y, long long cnt) {
	queue<tuple<long long,long long,long long>> q; 
	v[x][y]=1;
	q.push({x,y,cnt});
	while(!q.empty()) {
		tuple<long long,long long,long long> tar = q.front();
		q.pop();
		if(get<0>(tar)==tara && get<1>(tar)==tarb) {
			return get<2>(tar);
		}
		for(int i=0; i<8; i++) {
			long long nx = get<0>(tar)+dx[i];
			long long ny = get<1>(tar)+dy[i];
			if(0<=nx&&nx<l && 0<=ny&&ny<l && !v[nx][ny]) {
				v[nx][ny]=1;
				q.push({nx,ny,get<2>(tar)+1});
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	long long t;
	cin >> t;
	for(long long i=0; i<t; i++) {
		int a,b;
		fill(&v[0][0], &v[300][300], 0);
		cin >> l >> a >> b;
		cin >> tara >> tarb;	
		cout << bfs(a,b,0) << "\n";
	}
}