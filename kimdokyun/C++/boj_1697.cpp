#include<stdio.h>
#include<queue>
#include<utility>
using namespace std;

int value[200000];

int main() {
    int N,K;
    scanf("%d %d",&N,&K);
    queue<int> bfs;
    bfs.push(N);
    while(!bfs.empty()) {
        int now = bfs.front();
        bfs.pop();
        if(now == K) break;
        else {
            int next[3] = {now-1,now+1,now*2};
            for(int i=0;i<3;i++) {
                if(next[i] < 0 || (next[i] > 2*K && next[i]>now)) continue;
                if(value[next[i]]==0 && next[i]!=N) {
                    bfs.push(next[i]);
                    value[next[i]] = value[now]+1;
                }
            }
        } 
    }
    printf("%d",value[K]);
}