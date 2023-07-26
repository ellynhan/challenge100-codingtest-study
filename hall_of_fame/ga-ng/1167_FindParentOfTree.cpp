#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int num;
queue<int>q;
vector<int>v[100001];
int parent[100001];
void bfs(){
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int i=0;i<v[curr].size();i++){
            int next=v[curr][i];
            if(parent[curr]==next)continue;
            q.push(next);
            parent[next]=curr;
        }
    }
}

int main(void) {
    
    cin >> num;

    for (int i=1; i<num; i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    q.push(1);
    bfs();
    
    for(int i = 2; i<=num; i++)
        cout << parent[i] << endl;
}
