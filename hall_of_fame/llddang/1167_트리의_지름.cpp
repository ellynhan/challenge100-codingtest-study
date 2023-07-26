#include <iostream>
#include <vector>
using namespace std;

int N;
int maxCost, maxIdx;
bool visited[100001];
vector<pair<int, int>> graph[100001];

void init(){
    cin >> N;
    int idx, to, cost;
    for(int i=0; i<N; i++){
        cin >> idx >> to;
        while(to != -1){
            cin >> cost;
            graph[idx].push_back({to, cost});
            cin >> to;
        }
    }
}

void dfs(int idx, int cost){
    if(maxCost < cost){
        maxCost = cost;
        maxIdx = idx;
    }

    for(int i=0; i<graph[idx].size(); i++){
        int nextIdx = graph[idx][i].first;
        int nextCost = graph[idx][i].second;

        if(visited[nextIdx]) continue;

        visited[nextIdx] = true;
        dfs(nextIdx, cost + nextCost);
        visited[nextIdx] = false;
    }
}

int main(){
    init();

    visited[1] = true;
    dfs(1, 0);
    visited[1] = false;

    visited[maxIdx] = true;
    dfs(maxIdx, 0);

    cout << maxCost;
}
