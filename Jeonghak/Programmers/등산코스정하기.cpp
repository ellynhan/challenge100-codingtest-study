#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int *intensity;
bool isGate[50001] = {false, };
bool isSummit[50001] = {false, };

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vector<pair<int, int>> adjList[n + 1];
    intensity = new int[n+1];
    
    for(auto &gate : gates){
        isGate[gate] = true;
    }
    for(auto &summit: summits){
        isSummit[summit] = true;
    }
    
    for(auto &path : paths){
        int from = path[0];
        int to = path[1];
        int weight = path[2];
        // 출입구로 들어오는 경로, 산봉우리에서 나가는 경로는 추가 X
        if(!isSummit[from] && !isGate[to])
            adjList[from].push_back({to, weight});
        if(!isSummit[to] && !isGate[from] )
            adjList[to].push_back({from, weight});
    }
    
    // intensity, node를 담는 우선순위 큐
    queue<pair<int, int>> q;
    fill_n(intensity, n + 1, 0x7f7f7f7f);
    
    for(auto &gate : gates){
        q.push({0, gate});
    }
    
    while(!q.empty()){
        int curr_intensity = q.front().first;
        int curr = q.front().second;
        q.pop();

        // 현재 노드의 intensity가 더 크면 탐색 필요 x
        if(intensity[curr] <= curr_intensity)
            continue;
        intensity[curr] = curr_intensity;
        
        for(int i=0; i < adjList[curr].size(); i++){
            int next = adjList[curr][i].first;
            int next_intensity = max(curr_intensity, adjList[curr][i].second);
            if(intensity[next] <= next_intensity)
                continue;
            q.push({next_intensity, next});
        }
    }
    answer.push_back(0);
    answer.push_back(0x7f7f7f7f);
    
    sort(summits.begin(), summits.end());
    
    for(auto &summit : summits){
        if(intensity[summit] < answer[1]){
            answer[1] = intensity[summit];
            answer[0] = summit;
        }
    }
    
    return answer;
}