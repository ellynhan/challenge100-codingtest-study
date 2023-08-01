#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define FOR(i, j) for(int i = 0; i < j; i++)
#define INF 1987654321

vector<int> edge[101];
int N;

int countNodes(int node, int prevNode, int v1, int v2)
{
    int nodeCnt = 1;
    
    FOR(i, edge[node].size()) {
        if (edge[node][i] != prevNode &&
            edge[node][i] != v1 &&
            edge[node][i] != v2) {
                nodeCnt += countNodes(edge[node][i], node, v1, v2);
        }
    }
    return nodeCnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INF;
    N = n;
    
    FOR(i, wires.size()) {
        edge[wires[i][0]].push_back(wires[i][1]);
        edge[wires[i][1]].push_back(wires[i][0]);
    }
    
    int a, b;
    FOR(i, wires.size()) {
        a = countNodes(wires[i][0], -1, wires[i][0], wires[i][1]);
        b = countNodes(wires[i][1], -1, wires[i][0], wires[i][1]);
        // cout << a << ' ' << b << '\n';
        answer = min(abs(a - b), answer);
    }
    return answer;
}