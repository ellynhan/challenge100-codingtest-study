#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,k,a,b,destination;
int buildingTime[1000];
int visitTime[1000];
vector<int> nextNodes[1000];

void initialize(){
    for(int i=0; i<n; i++){
        visitTime[i]=0;
        nextNodes[i].clear();
    }
}

void input(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> buildingTime[i];
    }
    initialize();
    for(int i=0; i<k; i++){
        cin >> a >> b;
        nextNodes[a-1].push_back(b-1);
        visitTime[b-1]++;
    }
    cin >> destination;
}

void cal(){
    priority_queue<pair<int, int>> pq; //-built time(currTime + builtTime), node  
    for(int i=0; i<n; i++){
        if(visitTime[i]==0){
            pq.push({-buildingTime[i],i});
        }
    }
    int currTime = 0;
    while(!pq.empty()){
        int builtTime = -pq.top().first;
        int currBuilding = pq.top().second;
        pq.pop();
        if(currBuilding == destination-1){
            cout<<builtTime<<'\n';
            return;
        }
        for(int i=0; i<nextNodes[currBuilding].size(); i++){
            int next = nextNodes[currBuilding][i];
            if(visitTime[next]>1){
                visitTime[next]--;
            }else{
                pq.push({-(builtTime+buildingTime[next]),next});
            }
        }  
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int testcase;
    cin >> testcase;

    while(testcase--){
        input();        
        cal();
    }
}
