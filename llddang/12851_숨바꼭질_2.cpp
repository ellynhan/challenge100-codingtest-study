#include <iostream>
#include <queue>
using namespace std;

int N, K;
int answer = INT32_MAX;
int answer_cnt = 1;
int check[200001];

void solve(){
    queue<pair<int, int>> q;
    q.push({N, 0});
    
    for(int i=0; i<200001; i++) check[i] = INT32_MAX;
    check[N] = 0;

    int x, t, ft;
    while(!q.empty()){
        x = q.front().first; t = q.front().second;
        q.pop();

        if(answer < t) continue;
        if(K <= x){
            ft = t + x - K;
            if(ft < answer) answer = ft, answer_cnt = 1;
            else if(ft == answer) answer_cnt++;
            continue;
        }

        if(0 < x && t+1 <= check[x-1]) q.push({x-1, t+1}), check[x-1] = t+1;
        if(t+1 <= check[x+1]) q.push({x+1, t+1}), check[x+1] = t+1;
        if(t+1 <= check[x*2]) q.push({x*2, t+1}), check[x*2] = t+1;
    }

    return;
}

int main(){
    cin >> N >> K;

    solve();

    cout << answer << "\n" << answer_cnt;
}
