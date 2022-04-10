#include<iostream>
#include<vector>
#include<queue>
#define MAX 100001

using namespace std;
vector<int> treeMap[MAX];
int parentNodes[MAX];

void bfs()
{
    queue<int> q;
    q.push(1);
    parentNodes[1] = 1;
    while(!q.empty())
    {
        int currNode = q.front();
        q.pop();
        for(auto i=treeMap[currNode].begin(); i != treeMap[currNode].end(); i++)
        {
            int nextNode = *i;
            // 부모를 찾지 않은 노드이면
            if(parentNodes[nextNode] == 0){
                parentNodes[nextNode] = currNode;
                q.push(nextNode);
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        int node1, node2;
        cin >> node1 >> node2;
        treeMap[node1].push_back(node2);
        treeMap[node2].push_back(node1);
    }
    bfs();

    for(int i=2; i<=N; i++) cout << parentNodes[i] << '\n';
}