#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    ioboost;
    int n, m;
    cin >> n >> m;
    
    vector<int> back[32001];
    set<int> front[32001];
    int used[32001]={0};
    queue<int> nofront;

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        back[a].push_back(b);
        front[b].insert(a);
    }
    
    for(int i=1; i<=n; i++){
        if(front[i].size()==0){
            nofront.push(i);
        }
    }

    while(!nofront.empty()){
        int curr = nofront.front();
        cout<<curr<<" ";
        nofront.pop();
        used[curr]=1;
        for(int i=0; i<back[curr].size(); i++){
            int next = back[curr][i];
            front[next].erase(curr);
            if(front[next].size()==0){
                nofront.push(next);
            }
        }
    }
}
