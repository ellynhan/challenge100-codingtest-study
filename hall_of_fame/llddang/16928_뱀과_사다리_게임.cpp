#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[101];
bool visited[101] = {false};
struct node{int num, cnt;};

int bfs(int num){
    queue<node> q; q.push({num, 0});
    int next, cnt;
    node n;
    while(!q.empty()){
        n = q.front(); q.pop();
        num = n.num; cnt = n.cnt + 1;
        for(int i=1; i<=6; i++){
            if(num + i > 100) continue;
            next = arr[num + i];
            
            if(visited[next]) continue;
            if(next == 100) return cnt;

            q.push({next, cnt});
            visited[next] = true;
        }
    }
    return 0;
}

int main(){
    for(int i=0; i<101; i++) arr[i] = i;

    cin >> N >> M;
    int a, b;
    for(int i=0; i<N; i++) cin >> a >> b, arr[a] = b;
    for(int i=0; i<M; i++) cin >> a >> b, arr[a] = b;

    cout << bfs(arr[1]);
}
