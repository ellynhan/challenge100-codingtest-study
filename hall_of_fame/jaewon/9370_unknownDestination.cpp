#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
vector<pair<int, int>> way[2000]; //cost, node
int dp[3][2000];
vector<int> dest;
int n,m,t,s,g,h,a,b,d;

void initialize(){
    for(int i=0; i<n; i++){
        way[i].clear();
        dp[0][i]=INF;
        dp[1][i]=INF;
        dp[2][i]=INF;
    }
    dest.clear();
}

void input(){
    for(int i=0; i<m; i++){
        cin>>a>>b>>d;
        way[a-1].push_back({d,b-1});
        way[b-1].push_back({d,a-1});
    }
    for(int i=0; i<t; i++){
        int tmp;
        cin>>tmp;
        dest.push_back(tmp-1);
    }
    sort(dest.begin(), dest.end());
}

void dijkstra(int start, int currPhase){
    priority_queue<pair<int, int>> pq; //cost, curr
    pq.push({0,start});
    dp[currPhase][start]=0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        for(int i=0; i<way[curr].size(); i++){
            int nextDist = dist + way[curr][i].first;
            int next = way[curr][i].second;
            if(dp[currPhase][next]>nextDist){
                dp[currPhase][next]=nextDist;
                pq.push({-nextDist, next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testCase;
    cin >> testCase;
    while(testCase--){
        cin>>n>>m>>t>>s>>g>>h;
        initialize();    
        input();
        dijkstra(s-1,0);
        dijkstra(g-1,1);
        dijkstra(h-1,2);
        for(int i=0; i<dest.size(); i++){
            int d = dest[i];
            if((dp[0][d] == dp[0][g-1]+dp[1][h-1]+dp[2][d])||(dp[0][d] == dp[0][h-1]+dp[2][g-1]+dp[1][d])){
                cout<<d+1<<" ";
            }
            if(i==dest.size()-1){
                cout<<'\n';
            }
        } 
    }
}
