//0458~0555 0725~0900
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int numOfNodes, numOfEdges; //1번부터 numOfnodes번까지
    scanf("%d%d", &numOfNodes, &numOfEdges);
    vector<vector<int>> ways(numOfNodes,vector<int>(numOfNodes, INT32_MAX));
    vector<int> startDP(numOfNodes, INT32_MAX);
    vector<int> wayPointDP(numOfNodes, INT32_MAX);
    vector<int> wayPointDP2(numOfNodes, INT32_MAX);
    for(int i=0; i<numOfEdges; i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ways[a-1][b-1]=c;
        ways[b-1][a-1]=c;
    }
    int wayPoint[2]; //이 경로를 경유해야함
    scanf("%d%d",&wayPoint[0],&wayPoint[1]);
   
    //dij
    priority_queue<pair<int, int>> pq; //-cost, currNode
    pq.push({0,0});
    while(!pq.empty()){
        int dist = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(startDP[curr] < dist)continue;
        startDP[curr]=min(startDP[curr],dist);
        for(int i=0; i<numOfNodes; i++){
            if(ways[curr][i]!=INT32_MAX){
                pq.push({-(dist+ways[curr][i]),i});
            }
        }
    }
    pq.push({0,wayPoint[0]-1});
    while(!pq.empty()){
        int dist = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(wayPointDP[curr] < dist)continue;
        wayPointDP[curr]=min(wayPointDP[curr],dist);
        for(int i=0; i<numOfNodes; i++){
            if(ways[curr][i]!=INT32_MAX){
                pq.push({-(dist+ways[curr][i]),i});
            }
        }
    }
    pq.push({0,wayPoint[1]-1});
    while(!pq.empty()){
        int dist = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(wayPointDP2[curr] < dist)continue;
        wayPointDP2[curr]=min(wayPointDP2[curr],dist);
        for(int i=0; i<numOfNodes; i++){
            if(ways[curr][i]!=INT32_MAX){
                pq.push({-(dist+ways[curr][i]),i});
            }
        }
    }
    int case1Front = startDP[wayPoint[0]-1];
    int case2Front = startDP[wayPoint[1]-1];
    int case1Back = wayPointDP2[numOfNodes-1];
    int case2Back = wayPointDP[numOfNodes-1];
    int middle = +wayPointDP[wayPoint[1]-1];
    if((case1Front==INT32_MAX||case1Back==INT32_MAX)&&(case2Front==INT32_MAX||case2Back==INT32_MAX)){
        printf("%d",-1);
    }else if(middle == INT32_MAX){
        printf("%d",-1);
    }else{
        printf("%d",min(case1Front+case1Back, case2Front+case2Back)+middle);
    }
}
