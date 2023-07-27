#include <iostream>
#include <vector>
using namespace std;

void dfs_farm(int, int, vector<vector<int>>& );

int farmX, farmY;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase; cin >> testCase;
    while(testCase > 0){
        cin >> farmX >> farmY;
        vector<vector<int>> farm(farmX, vector<int>(farmY,0));
        int cabbageN; cin >> cabbageN;
        while(cabbageN > 0){
            int tmpX, tmpY; cin >> tmpX >> tmpY;
            farm[tmpX][tmpY] = 1;
            cabbageN--;
        }

        int cnt = 0;
        for(int i=0; i<farmX; i++){
            for(int j=0; j<farmY; j++){
                if(farm[i][j] == 1){
                    cnt++;
                    farm[i][j] = 2;
                    dfs_farm(i, j, farm);
                }
            }
        }

        cout << cnt << "\n";
        farm.clear();
        testCase--;
    }
}

int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

void dfs_farm(int x, int y, vector<vector<int>>& vec){
    for(int i=0; i<4; i++){
        int currX = x + dx[i];
        int currY = y + dy[i];

        if(currX < 0 || currX >= farmX ||
           currY < 0 || currY >= farmY)
            continue;
        if(vec[currX][currY] == 1){
            vec[currX][currY] = 2;
            dfs_farm(currX, currY, vec);
        }
    }

}
