#include<iostream>
#include<vector>
#include<cstring>
 
using namespace std;

struct pos{int i,j;};
vector<pos> pieces;
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
int answer = 50;
bool used[5][5], visited[5][5];
 
int count(pos p){
    int i = p.i, j = p.j;
    visited[i][j] = true;
    int cnt = 1;

    for(int k=0; k<4; k++){
        int ni = i + di[k];
        int nj = j + dj[k];

        if(0 > ni || ni >= 5 || 0 > nj || nj >= 5) continue;
        if(!used[ni][nj] || visited[ni][nj]) continue;
        
        cnt += count({ni,nj});
    }
    return cnt;
}
 
pos findFirstPos(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(used[i][j]) return {i, j};
        }
    }
    return {-1, -1};
}
 
bool isConnect(){
    memset(visited,false,sizeof(visited));
    return count(findFirstPos()) == pieces.size();
}
 
void bruteForce(int n,int dist){
    if(answer <= dist)return;

    if(n == pieces.size()){
        if(dist < answer && isConnect()) answer = dist;
        return;
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(used[i][j]) continue;

            used[i][j] = true;
            bruteForce(n+1, dist + abs(pieces[n].i - i) + abs(pieces[n].j - j));
            used[i][j] = false;
        }
    }
}
 
int main(){
    string input;
    for(int i=0; i<5; i++){
        cin >> input;
        for(int j=0; j<5; j++)
            if(input[j] == '*') pieces.push_back({i, j});
    }
    memset(used,false,sizeof(used));
    
    bruteForce(0,0);
    cout << answer << "\n";

    return 0;
}
