#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int visit[8]={0};
vector<vector<int>> d;
int maxVisit = 0;
void dfs(int numOfVisited, int curr, int left){
    maxVisit = max(maxVisit, numOfVisited);
    for(int i=0; i<d.size(); i++){
        if(visit[i]==1)continue;
        int need = d[i][0];
        int consume = d[i][1];
        if(left>=need){
            visit[i]=1;
            dfs(numOfVisited+1, i, left-consume);
            visit[i]=0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    d = dungeons;
    for(int i=0; i<dungeons.size(); i++){
        visit[i]=1;
        dfs(1,i,k-dungeons[i][1]);
        visit[i]=0;
    }
    return maxVisit;
}
