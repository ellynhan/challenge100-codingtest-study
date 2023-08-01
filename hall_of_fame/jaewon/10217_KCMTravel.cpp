#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Info{
    int end;
    int cost;
    int dist;
    Info(int e, int c, int d):end(e),cost(c),dist(d){}
}info;

struct compare{
    bool operator()(Info a, Info b){
        return a.dist > b.dist;
    };
};

int n,m,k,u,v,c,d;
// vector<pair<int, int>> cost_dist[100][100]; //i에서 j까지
vector<info> city[100];
int dp[100][10001]; //i까지 j의 비용을 들여서 도착했을 때 최소 거리
int minValue;


void initializeAndInput(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        city[i].clear();
        for(int j=0; j<10001; j++){
            dp[i][j]=INT32_MAX;
        }
    }
    for(int i=0; i<k; i++){
        cin >> u >> v >> c >> d;
        city[u-1].push_back(info(v-1,c,d));
    }
    minValue = INT32_MAX;   
}

void dij(){
    priority_queue<info, vector<info>, compare> pq;
    pq.push(info(0,0,0)); //end cost dist
    dp[0][0]=0; //to node0 with cost0's dist =0
    while(!pq.empty()){
        int currNode = pq.top().end;
        int currDist = pq.top().dist;
        int currCost = pq.top().cost;
        pq.pop();

        if(currCost>m)continue;
        if(dp[currNode][currCost]<currDist)continue;
        if(currNode == n-1){
            minValue = min(minValue, currDist);
            continue;
        }

        for(int i=0; i<city[currNode].size(); i++){
            int nextNode = city[currNode][i].end;
            int nextDist = currDist + city[currNode][i].dist;
            int nextCost = currCost + city[currNode][i].cost;

            if(nextCost<=m && dp[nextNode][nextCost]>nextDist){
                dp[nextNode][nextCost]=nextDist;

                for(int j=nextCost+1; j<=m; j++){
                    if(dp[nextNode][j] <= nextDist)break;
                    dp[nextNode][j]=nextDist;
                }

                pq.push(info(nextNode,nextCost,nextDist));
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int testCase;
    cin >> testCase;
    while(testCase--){
        initializeAndInput();
        dij();
        if(minValue == INT32_MAX){
            cout<<"Poor KCM\n";
        }else{
            cout<<minValue<<'\n';
        }
    }
}
