#include<iostream>
#include<vector>
#include<cstring>
#define MAX 10001
using namespace std;

struct Node {
    int child;
    int cost;
};

int N, max_cost, end_node;
vector<Node> Tree[MAX];
bool visit[MAX];

void Input()
{
    int n1, n2, cost;
    cin >> N;
    for(int i=0; i<N-1; i++){
        cin >> n1 >> n2 >> cost;
        Tree[n1].push_back({n2, cost});
        Tree[n2].push_back({n1, cost});
    }
}

void DFS(int curr_node, int curr_cost)
{
    visit[curr_node] = true;

    if(max_cost < curr_cost){
        max_cost = curr_cost;
        end_node = curr_node;
    }

    for(auto node: Tree[curr_node]){
        int next_node = node.child;
        int next_cost = node.cost + curr_cost;
        if(!visit[next_node]){
            visit[next_node] = true;
            DFS(next_node, next_cost);
        }
    }
}

int main()
{
    Input();
    DFS(1, 0);
    memset(visit, false, sizeof(visit));
    max_cost = 0;
    DFS(end_node, 0);
    cout << max_cost;
    return 0;
}