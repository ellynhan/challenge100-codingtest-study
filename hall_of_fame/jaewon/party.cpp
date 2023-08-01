#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 1000
#define MAX_M 10000
#define MAX_T 987654321

int road[MAX_N+1][MAX_N+1];

int main(){
	int N, M, X, s, e, t;
	cin >> N >> M >> X;
	for(int i=0; i<N+1; i++){
		for(int j=0; j<N+1; j++){
			road[i][j] = MAX_T; 
		}
	}
	for(int i=0; i<M; i++){
		cin >> s >> e >> t;
		road[s][e] = t;
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			for(int k=1; k<=N; k++){
				road[j][k] = min(road[j][k], road[j][i]+road[i][k]);
			}
		}
	}
	int ans = 0;
	for(int i=1; i<=N; i++){
		if(i!=X)
			ans = max(ans, road[i][X]+road[X][i]);
	}
	cout<<ans;
}