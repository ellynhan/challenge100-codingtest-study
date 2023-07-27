//0443

#include <iostream>
#include <queue>
using namespace std;
int n,m;
int board[1001][1001]={0,};
int visit[1001][1001][2]={0,};
int xx[4]={0,0,-1,1};
int yy[4]={-1,1,0,0};

typedef struct Info{
    int x, y;
    bool isBreak = false;
    int cnt = 0;
    Info(int X, int Y, bool B, int C):x(X), y(Y), isBreak(B), cnt(C){};
}info; 

int bfs(){
    queue<info> q;
    q.push(info(0,0,false,1));
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        bool isBreak = q.front().isBreak;
        int cnt = q.front().cnt;
        q.pop();
        if(y==n-1&&x==m-1){
            cout<<cnt;
            return 1;
        }
        for(int i=0; i<4; i++){
            int Y = y+yy[i];
            int X = x+xx[i];
            if(X<0||Y<0||X>=m||Y>=n)continue;
            if(board[Y][X]==0&&isBreak==false&&visit[Y][X][0]==0){
                q.push(info(X,Y,isBreak,cnt+1));
                visit[Y][X][0]=1;
            }
            else if(board[Y][X]==0&&isBreak==true&&visit[Y][X][1]==0){
                q.push(info(X,Y,isBreak,cnt+1));
                visit[Y][X][1]=1;
            }else if(board[Y][X]==1&&isBreak==false){
                q.push(info(X,Y,true,cnt+1));
                visit[Y][X][1]=1;
            }
        }
    }
    return 0;
}


int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string tmp ;
        cin >> tmp;
        for(int j=0; j<m; j++){
            board[i][j] = tmp[j]-'0';
        }
    }
    if(bfs()==0){
        cout<<-1;
    }
}
