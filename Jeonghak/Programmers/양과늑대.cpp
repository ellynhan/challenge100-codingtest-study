#include <string>
#include <vector>
#include <map>

using namespace std;

int max_sheep = 0;
map<int, vector<int>> tree;
vector<int> next_node;
vector<int> isSheep;

void dfs(int node, int woolf, int sheep, vector<int> &next_nodes){
    if(isSheep[node] == 0) sheep++;
    else woolf++;
    
    max_sheep = max(max_sheep, sheep);

    if(woolf >= sheep) return;
    
    for(int i=0;i<next_nodes.size();++i) {
        vector<int> next = next_nodes;
        next.erase(next.begin() + i);
        
        for(auto &child : tree[next_nodes[i]]) {
            next.push_back(child);
        }
        
        dfs(next_nodes[i], woolf, sheep, next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    isSheep = info;
    
    for(auto edge : edges){
        tree[edge[0]].push_back(edge[1]);
    }
    
    dfs(0, 0, 0, tree[0]);
    
    answer = max_sheep;
    return answer;
}