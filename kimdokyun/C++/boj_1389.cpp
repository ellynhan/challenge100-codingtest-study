#include<stdio.h>

int graph[101][101];

int main() {
    int N,M;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        graph[i][j] = i==j?0:9999;
    }
    for(int i=0;i<M;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a][b] = graph[b][a] = 1;
    }
    for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                int pass_k = graph[i][k] + graph[k][j];
                graph[i][j] = graph[i][j] > pass_k? pass_k:graph[i][j];
            }
        }
    }
    int result = 0, min = 9999;
    for(int i=1;i<=N;i++) {
        int sum = 0;
        for(int j=1;j<=N;j++) sum+=graph[i][j];
        if(min > sum) {
            result = i;
            min = sum;
        }
    }
    printf("%d",result);
}