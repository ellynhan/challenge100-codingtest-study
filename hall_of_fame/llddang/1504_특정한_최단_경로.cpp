#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, E;
int value[801][801];
vector<pair<int, int>> edge[801];
vector<int> vec(4);


void init(){
    cin >> N >> E;

    for(int i=1; i<=N; i++)
    for(int j=1; j<=N; j++)
        value[i][j] = INF;

    int v1, v2, dist;
    for(int i=0; i<E; i++){
        cin >> v1 >> v2 >> dist;
        edge[v1].push_back({dist, v2});
        edge[v2].push_back({dist, v1});
    }
    
    vec[0] = 1;
    cin >> vec[1] >> vec[2];
    vec[3] = N;
}

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

    int dist, idx, next_dist, next_idx;
    for(int v:vec){
        pq.push({0, v});
        value[v][v] = 0;

        while(!pq.empty()){
            dist = pq.top().first;
            idx = pq.top().second;
            pq.pop();

            for(int i=0; i<edge[idx].size(); i++){
                next_dist = edge[idx][i].first;
                next_idx = edge[idx][i].second;

                if(value[v][next_idx] <= dist + next_dist) continue;

                value[v][next_idx] = dist + next_dist;
                value[next_idx][v] = dist + next_dist;

                pq.push({dist+next_dist, next_idx});
            }
        }
    }
}

void solve(){
    int v1 = vec[1], v2 = vec[2];

    int answer = INF;
    if(value[1][v1] != INF && value[v1][v2] != INF && value[v2][N] != INF)
        answer = min(answer, value[1][v1] + value[v1][v2] + value[v2][N]);
    if(value[1][v2] != INF && value[v2][v1] != INF && value[v1][N] != INF)
        answer = min(answer, value[1][v2] + value[v2][v1] + value[v1][N]);

    if(answer == INF) cout << -1;
    else cout << answer;
}

int main(){
    init();
    dijkstra();
    solve();
}
