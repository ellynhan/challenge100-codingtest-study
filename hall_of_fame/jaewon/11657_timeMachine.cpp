#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1987654321

typedef struct Info{
    int start;
    int end;
    int dist;
    Info(int s, int e, int d): start(s), end(e), dist(d){};
}info;

int n,m,a,b,c;
vector<pair<int,int>> ways[500]; //dist(cost), next
vector<info> wayInfo;
long long dp[500];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        dp[i]=INF;
    }
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        ways[a-1].push_back({c,b-1});
        wayInfo.push_back(info(a-1,b-1,c));
    }

    queue<int> q;
    q.push(0);
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int start = wayInfo[j].start;
            int end = wayInfo[j].end;
            int dist = wayInfo[j].dist;
            if(dp[start]!=INF && dp[end]>dp[start]+dist){
                if(i==n-1){ //무한루프 간주
                    cout<<-1; 
                    return 0;
                }
                dp[end]=dp[start]+dist;
            }
        }
    }
    for(int i=1; i<n; i++){
        if(dp[i]==INF){
            cout<<-1<<"\n";
        }else{
            cout<<dp[i]<<"\n";
        }   
    }
}
