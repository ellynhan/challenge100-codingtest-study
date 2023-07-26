#include <iostream>
#include <queue>
using namespace std;

int xx[8]={-2,-1,1,2,2,1,-1,-2};
int yy[8]={1,2,2,1,-1,-2,-2,-1};
int mini = 1000;

void bfs(pair<int, int> start, pair<int, int> goal, int len, vector<vector<int>>& v){
    queue<pair<pair<int, int>,int>> q;
    q.push({start,0});
    while(!q.empty()){
        pair<int, int> curr = q.front().first;
        int cnt = q.front().second;
        if(curr == goal){
            mini = min(mini, cnt);
        }
        q.pop();
        for(int i=0; i<8; i++){
            int Y = curr.first + yy[i];
            int X = curr.second + xx[i];
            if(X<0||Y<0||X>=len||Y>=len)continue;
            if(v[Y][X]==0){
                v[Y][X]=1;
                q.push({{Y,X},cnt+1});
            }
        }
    }
}

int main(){
    int testCase;
    cin >> testCase;
    while(testCase--){
        int len;
        cin >> len;
        pair<int, int> curr;
        pair<int, int> goal;
        cin >> curr.first >> curr.second;
        cin >> goal.first >> goal.second;
        vector<vector<int>> v(len, vector<int>(len,0));
        bfs(curr,goal,len, v);
        cout<<mini<<endl;
        mini = 1000;
    }
}
