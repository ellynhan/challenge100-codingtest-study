#include <stdio.h>

const int LM = 50005;
int N, M, group[LM];

int find(int k){
    if(group[k] == k) return k;
    return group[k] = find(group[k]);
}

int main(){
    scanf("%d%d", &N, &M);
    int ans=N;
    int i,j,u,v; 
    for(i =1 ; i<=N; i++){
        group[i] = i;
    }
    for(i=0; i<M; i++){
        scanf("%d%d", &u,&v);
        // u = group[u], v = group[v];
        u = find(u), v = find(v);
        if(u==v)continue;
        ans --;
        // for(j=1; j<N; j++){
        //     if(group[i]==v){
        //         group[i]=u;
        //     }
        // }
        group[v] = u;
    }
    printf("%d", ans);
}