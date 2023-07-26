#include <iostream>
#include <queue>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
//1037 ~ 57

int G[100][100];
int n;

void bfs(int start){
    int visited[100][100]={0};
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(G[curr][i]==1 && visited[curr][i]==0){
                visited[curr][i] = 1;
                G[start][i]=1;
                q.push(i);
            }
        }
    }
}

int main(){
    ioboost;;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> G[i][j];
        }
    }

    for(int i=0; i<n; i++){
        bfs(i);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<G[i][j]<<" ";
        }
        cout<<"\n";
    }
}
