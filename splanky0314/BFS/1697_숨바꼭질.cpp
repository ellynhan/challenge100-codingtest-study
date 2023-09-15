#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool v[200000];

int bfs(int x, int k, int cnt) {
	queue<pair<int,int>> q;
	v[x]=1;
	q.push({x,cnt});
	while(!q.empty()) {
		pair<int,int> tar = q.front();
		if(tar.first==k) return tar.second;
		q.pop();
		for(int i=0; i<3; i++) {
			if(i==0 && tar.first+1<=100000 && !v[tar.first+1]) {
				q.push({tar.first+1,tar.second+1});
				v[tar.first+1]=1;
			}
			else if(i==1 && tar.first-1>=0 && !v[tar.first-1]) {
				q.push({tar.first-1, tar.second+1});
				v[tar.first-1]=1;
			}
			else if(i==2 && tar.first*2<=100000 && !v[2*tar.first]){
				q.push({2*tar.first, tar.second+1});
				v[tar.first*2]=1;
			}
		}
	} 
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int n,k;
	cin >> n >> k;
	cout << bfs(n,k,0);
}