#include <iostream>
#include <queue>
using namespace std;

int M, N;

int garden[50][50]={0,};
int visited[50][50]={0,};

//상하좌우
int xx[4] = {0,0,-1,1};
int yy[4] = {1,-1,0,0};

//first = y, second = x
void bfs(pair<int, int> curr){
    queue<pair<int, int> > around ;
    visited[curr.first][curr.second] = 1;
    around.push(curr);
    while(!around.empty()){
        pair<int, int> next = around.front();
        around.pop();
        
        for(int i=0; i<4; i++){
            int y = next.first + yy[i];
            int x = next.second + xx[i];
            if(y>=0 && x>=0 && y<N && x<M && garden[y][x]==1 && visited[y][x]==0){
                around.push({y,x});
                visited[y][x] = 1;
            }
        }
    }

}


int main(){
    int T, K; 
    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                garden[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        for(int i=0; i<K; i++){
            int x, y;
            cin >> x >> y ;
            garden[y][x] = 1;
        }

        int worms = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(garden[i][j]==1 && visited[i][j]==0){
                    bfs({i,j});
                    worms ++;
                }
            }
        }
        cout << worms<<endl;
        
    }

}
