#include <iostream>
#include <vector>
#include <string.h>


using namespace std;

bool farm[51][51] = {0,};

bool visited[51][51] = {0,};

int m,n;

int dy[] = {0, -1, 1, 0};
int dx[] = {-1, 0, 0, 1};

void dfs(int x, int y){
    visited[x][y] = true;

    for(int i=0; i<4; i++){
        int ax = x + dx[i];
        int ay = y + dy[i];

        if(ax < 0 || ay < 0 || ax >= m || ay >= n )
            continue;

        if(!farm[ax][ay] || visited[ax][ay])
            continue;

        dfs(ax,ay);
    }
}

int main(void){
    int num,x,y,k;

    cin >> num;

    while(num>0){
        cin >> m >> n >> k;

        for(int i=0; i<k; i++){
            cin >> x >> y;
            farm[x][y] = true;
        }

        int worm = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(farm[i][j]==1 && !visited[i][j]){
                    worm++;
                    dfs(i,j);
                }
            }
        }

    cout << worm << "\n";

    memset(farm, 0, sizeof(farm));
    memset(visited, 0, sizeof(visited));

    num--;
    }


    return 0;
}
