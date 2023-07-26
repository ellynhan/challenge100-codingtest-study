#include <string>
#include <vector>
#include <queue>
using namespace std;
int conn[101][101]={0};
int maxNum;
int bfs_checkNum(){
    int cnt = 0;
    int visited[101]={0};
    int trying = 0;
    for(int i=1; i<=maxNum; i++){
        if(visited[i]==0){
            queue<int> q;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                if(trying==0){
                    cnt++;
                }else{
                    cnt--;
                }
                for(int j=1; j<=maxNum; j++){
                    if(conn[curr][j]==1 && visited[j]==0){
                        q.push(j);
                        visited[j]=1;
                    }
                }
            }
            trying ++;
        }
    }
    if(cnt >= 0){
        return cnt;
    }else{
        return -cnt;
    }
}

int solution(int n, vector<vector<int>> wires) {
    maxNum = n;
    int minAnswer = INT32_MAX;
    for(int i=0; i<wires.size(); i++){
        conn[wires[i][0]][wires[i][1]]=1;
        conn[wires[i][1]][wires[i][0]]=1;
    }
    for(int i=0; i<wires.size(); i++){
        conn[wires[i][0]][wires[i][1]]=0;
        conn[wires[i][1]][wires[i][0]]=0;
        int tmp = bfs_checkNum();
        minAnswer = min(minAnswer,tmp);
        conn[wires[i][0]][wires[i][1]]=1;
        conn[wires[i][1]][wires[i][0]]=1;
    }
    return minAnswer;
}
