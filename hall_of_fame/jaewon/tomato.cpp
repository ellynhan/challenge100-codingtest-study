#include <iostream>
#include <queue>
using namespace std; 

int box[101][101][101]; //h,y,x
typedef struct point{
    int x, y, h;
    point(int H, int Y, int X) : x(X), y(Y), h(H){} 
}p;

//왼  오  앞 뒤  아래  위
int xx[6] = {-1,1,0,0,0,0};
int yy[6] = {0,0,-1,1,0,0};
int hh[6] = {0,0,0,0,1,-1};
int m,n,h;
queue<pair<p,int>> q;
int cnt = 0;
int maxDay = 0;

void bfs(){
    while(!q.empty()){
        pair<p,int> next = q.front();
        q.pop();
        for(int i=0; i<6; i++){
            int X = next.first.x + xx[i];
            int Y = next.first.y + yy[i];
            int H = next.first.h + hh[i];
            if(X<0||Y<0||H<0||X>=m||Y>=n||H>=h)continue;
            if(box[H][Y][X]==0){
                q.push({p(H,Y,X),next.second+1});
                maxDay = max(maxDay, next.second+1);
                cnt --;
                box[H][Y][X]=1;
            }
        }
    }
}


int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    cin>>m>>n>>h;

    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> box[i][j][k];
                if(box[i][j][k]==0){
                    cnt ++;
                }
                if(box[i][j][k]==1){
                    q.push({p(i,j,k),0});
                }
            }
        }
    }
    bfs();
    if(cnt == 0){
        cout<<maxDay;
    }else{
        cout<<-1;
    }
}  

