#include <iostream>
#include <queue>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int babysharkSize=2;
int space[20][20];
int visited[20][20]={0};
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};


struct Info{
    int x,y,time;
    Info(int Y, int X, int Time):y(Y), x(X), time(Time){}
};

bool isEatible(Info info){
    int y = info.y;
    int x = info.x;
    if(space[y][x]!=0 && space[y][x] < babysharkSize){
        return true;
    }
    return false;
}

struct compare{
    bool operator()(Info a, Info b){
        if(a.time < b.time){
            return false;
        }else if(a.time == b.time){
            if(isEatible(a) && !isEatible(b)){
                return false;
            }
            if(!isEatible(a) && isEatible(b)){
                return true;
            }
            if(a.y > b.y){
                return true;
            }else{
                return (a.y == b.y && a.x > b.x);
            }
        }else {
            return true;
        }
    }
};


int bfs(Info start){
    priority_queue<Info, vector<Info>, compare> q;
    q.push(start);
    int result = 0;
    int consume = 0;

    while(!q.empty()){
        Info curr = Info(q.top().y, q.top().x, q.top().time);
        q.pop();

        if(isEatible(curr)){
            while(!q.empty())q.pop();
            consume += 1;
            if(consume == babysharkSize){
                consume = 0;
                babysharkSize += 1;
            }
            space[curr.y][curr.x]=0;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    visited[i][j] = 0;
                }
            }
            
            result = curr.time;
        }

        visited[curr.y][curr.x] = 1;   

        for(int i=0; i<4; i++){
            int Y = curr.y + dy[i];
            int X = curr.x + dx[i];
            if(Y<0 || X<0 || Y>=n || X >=n)continue;
            if(space[Y][X]<=babysharkSize && visited[Y][X]==0){
                visited[Y][X]=1;
                q.push(Info(Y,X,curr.time+1));
            }
        }
    }
    return result;
}

int main(){
    ioboost;
    cin >> n;
    int startY, startX;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> space[i][j];
            if(space[i][j]==9){
                startY = i;
                startX = j;
                space[i][j]=0;
            }
        }
    }
    Info start(startY, startX, 0);
    cout<<bfs(start);
}