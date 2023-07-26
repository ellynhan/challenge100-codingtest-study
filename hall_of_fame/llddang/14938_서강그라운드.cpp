#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, R;
int arr[101];
vector<pair<int, int>> graph[101];
int value[101][101];
int answer = 0;

void solve(){
    for(int i=1; i<=N; i++)
    for(int j=1; j<=N; j++) value[i][j] = INF;

    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    
    int idx, cost, next_idx, next_cost;
    for(int i=1; i<=N; i++){
        value[i][i] = 0;
        pq.push({0, i});

        while(!pq.empty()){
            cost = pq.top().first;
            idx = pq.top().second;
            pq.pop();

            for(int j=0; j<graph[idx].size(); j++){
                next_cost = graph[idx][j].first;
                next_idx = graph[idx][j].second;

                if(M < cost + next_cost) continue;
                if(value[i][next_idx] <= cost + next_cost) continue;

                value[i][next_idx] = cost + next_cost;

                pq.push({cost+next_cost, next_idx});
            }
        }
    }

    int sum;
    for(int i=1; i<=N; i++){
        sum = 0;
        for(int j=1; j<=N; j++){
            if(value[i][j] <= M) sum += arr[j];
        }
        answer = max(answer, sum);
    }
}

int main(){
    cin >> N >> M >> R;
    for(int i=1; i<=N; i++) cin >> arr[i];
    int fr, to, cost;
    for(int i=0; i<R; i++){
        cin >> fr >> to >> cost;
        graph[fr].push_back({cost, to});
        graph[to].push_back({cost, fr});
    }

    solve();

    cout << answer;
}
