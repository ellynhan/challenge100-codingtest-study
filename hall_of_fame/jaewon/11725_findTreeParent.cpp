#include <iostream>
#include <vector>
#define boost ios::sync_with_stdio(false), cin.tie(0)
using namespace std;


int parents[100001] = {0};
int visited[100001] = {0};
vector<int> tree[100001];

void findParent(int node){
    visited[node] = 1;

    for(int i=0; i<tree[node].size(); i++){
        int next = tree[node][i];
        if(!visited[next]){
            parents[next] = node;
            findParent(next); 
        }
    }
}


int main(){
    boost;
    int nums;
    cin >> nums;
    for(int i=2; i<=nums; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    findParent(1);

    for(int i=2; i<=nums; i++){
        cout<<parents[i]<<'\n';
    }
}
