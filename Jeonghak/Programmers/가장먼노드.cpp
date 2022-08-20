#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(vector<int> &dist, vector<vector<int>> &graph){
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    
    while(q.empty() == false) {
        int from = q.front();
        q.pop();
        for(auto to : graph[from]){
            if(dist[to] == -1){
                dist[to] = dist[from] + 1;
                q.push(to);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    int max_distance;
    vector<vector<int>> graph(n+1);
    vector<int> distances(n+1, -1);
    
    for(auto edge: edges){
        int from = edge[0];
        int to = edge[1];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }   
    
    bfs(distances, graph);
    
    sort(distances.begin(), distances.end());
    max_distance = distances[n];
    
    for(auto distance: distances) {
        if(distance == max_distance) answer++;
    } 
    
    return answer;
}