#include<iostream>
#include<vector>
#include<cstring>
#define MAX 100001

using namespace std;

vector<pair<int, int>> Tree[MAX];
int N, end_node, max_cost;
bool visit[MAX];
void Input()
{   
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int from;
        cin >> from;
        while(true)
        {
            int to, cost;
            cin >> to;
            if(to == -1) break;
            cin >> cost;
            Tree[from].push_back({to, cost});
        }
    }
}

void DFS(int curr_node, int curr_cost)
{
    visit[curr_node] = true;
    if(curr_cost > max_cost)
    {
        max_cost = curr_cost;
        end_node = curr_node;
    }

    for(auto node: Tree[curr_node]){
        int next_node = node.first;
        int next_cost = node.second + curr_cost;
        if(!visit[next_node])
        {
            visit[next_node] = true;
            DFS(next_node, next_cost);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    Input();
    DFS(1, 0);
    memset(visit, false, sizeof(visit));
    max_cost = 0;
    DFS(end_node, 0);

    cout << max_cost;
}