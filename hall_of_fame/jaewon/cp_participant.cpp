#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

const int LM = 100005;
using pii = pair<int, int>;
int N, M, fsum, fcnt;
bool act[LM];

priority_queue<pii, vector<pii>, less<pii>> maxpq;
priority_queue<pii, vector<pii>, greater<pii>> minpq;

void push(auto id, int fr){
    act[id] = 1;
    fsum += fr, fcnt ++;
    maxpq.push({fr, id});
    minpq.push({fr, id});
}

void pop(auto& pq){
    if(fcnt == 0)return;
    printf("%d\n", pq.top().second);
    fcnt --;
    fsum -= pq.top().first;
    act[pq.top().second] = false;
    pq.pop();
}

int main(){
    scanf("%d %d", &N, &M);
    int cmd, id, fr;
    for(int i=0; i<M; i++){
        scanf("%d", &cmd);
        while(!minpq.empty() && !act[minpq.top().second]) minpq.pop();
        while(!maxpq.empty() && !act[maxpq.top().second]) maxpq.pop();
        if(cmd == 0){
            scanf("%d %d", &id, &fr);
            push(id, fr);
        }else if(cmd == 1){
            pop(minpq);
        }else if(cmd ==2){
            pop(maxpq);
        }else{
            if(fcnt < 3) printf("0\n");
            else printf("%d\n", fsum - minpq.top().first - maxpq.top().first);
        }
    }
}