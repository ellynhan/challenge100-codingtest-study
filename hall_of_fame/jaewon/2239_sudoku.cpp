#include <iostream>
#include <vector>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int board[9][9];
int rows[9][10]={0};
int columns[9][10]={0};
int blocks[3][3][10]={0};
vector< pair<int,int> > blank;

bool dfs(int index){
    if(index == blank.size()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<board[i][j];
            }
            cout<<'\n';
        }
        return true;
    }

    int y = blank[index].first;
    int x = blank[index].second;

    for(int i=1; i<=9; i++){
        if(rows[y][i]==0 && columns[x][i]==0 && blocks[y/3][x/3][i]==0){
            board[y][x] = i;
            rows[y][i]=1;
            columns[x][i]=1;
            blocks[y/3][x/3][i]=1;
            if(dfs(index+1)){
                return true;
            }else{
                board[y][x] = 0;
                rows[y][i]=0;
                columns[x][i]=0;
                blocks[y/3][x/3][i]=0;
            };   
        }
    }
    return false;
}

int main(){
    ioboost;
    for(int i=0; i<9; i++){
        string tmp;
        cin >> tmp;
        for(int j=0; j<9; j++){
            board[i][j] = tmp[j]-'0';
            if(board[i][j]==0){
                blank.push_back({i,j});
            }
            rows[i][board[i][j]]=1;
            columns[j][board[i][j]]=1;
            blocks[i/3][j/3][board[i][j]]=1;
        }
    }
    dfs(0);
}