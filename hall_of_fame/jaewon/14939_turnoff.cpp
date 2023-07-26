#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

int curr[10][10]= {0};
int bulb[10][10]= {0};

int xx[4] = {-1,0,1,0};
int yy[4] = {0,-1,0,1};
int checked[1<<10] = {0};
int minToggle = 101;

void toggle(int y, int x) {
    curr[y][x] = 1 - curr[y][x];
    for(int i=0; i<4; i++){
        int Y = y + yy[i];
        int X = x + xx[i];
        if(Y<0 || X<0 || Y>9 || X >9)continue;
        curr[Y][X] = 1 - curr[Y][X];
    }
}

void checkBulbs(int toggleCnt) {
    for(int i=0; i<10; i++){
        if(curr[9][i]==1){
            return ;
        }
    }

    if(minToggle > toggleCnt){
        minToggle = toggleCnt;
    }
}

void startToggle(int bit){
    int toggleCnt = 0;
    memcpy(curr, bulb, sizeof(bulb));

    //firstRow
    for(int i=0; i<10; i++){
        if((bit&(1<<i))!=0){
            toggle(0,i);
            toggleCnt++;
        }
    }

    for(int i=0; i<9; i++){
        for(int j=0; j<10; j++){
            if(curr[i][j]==1){
                toggle(i+1,j);
                toggleCnt++;
            }
        }
    }

    checkBulbs(toggleCnt);
}

void dfsFirstRow(int bit) {
    startToggle(bit);
    for(int i=0; i<10; i++){
        if( (bit&(1<<i)) != 0 || checked[bit|(1<<i)]==1) continue;
        checked[bit|(1<<i)] = 1;
        dfsFirstRow(bit|(1<<i));
    }
}

int main(){
    for(int i=0; i<10; i++){
        string row;
        cin >> row;
        for(int j=0; j<10; j++){
            if(row[j]=='#'){
                bulb[i][j]=0;
            }else{
                bulb[i][j]=1;
            }
        }
    }   
    dfsFirstRow(0);
    if(minToggle == 101){
        cout<<-1;
    }else{
        cout<<minToggle;
    }
}
