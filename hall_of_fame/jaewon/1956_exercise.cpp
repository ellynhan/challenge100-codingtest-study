#include <iostream>
using namespace std;
#define INF 8765432

int v,e,a,b,c;
int minValue=INF;
int DP[400][400];

void initialize(){
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            DP[i][j]=INF;
        }
    }
}

void input(){
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        DP[a-1][b-1]=c;
    }
}

void floyd(){
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            for(int k=0; k<v; k++){
                DP[i][j] = min(DP[i][j], DP[i][k]+DP[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> v >> e;  
    initialize();
    input();
    floyd();

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            minValue = min(minValue, DP[i][j]+DP[j][i]);
        }
    }
    if(minValue!=INF){
        cout<<minValue;
    }else{
        cout<<-1;
    }
}
