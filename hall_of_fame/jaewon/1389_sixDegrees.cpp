//0228~
#include <iostream>
#include <queue>
using namespace std;
//start에서 모든 방향으로의 최단거리는 floyd..?
#define relMax 7
int conn[101][101];
int users, rels;

void floyd() {
    for(int i=1; i<=users; i++){
        for(int j=1; j<=users; j++){
            for(int k=1; k<=users; k++){
                conn[j][k] = min(conn[j][k], conn[j][i] + conn[i][k]);
            }
        }
    }
}

int calcMin() {
    int min = 7*users;
    int minUser = 0;
    for(int i=1; i<=users; i++){
        int tmp = 0;
        for(int j=1; j<=users; j++){
            tmp += conn[i][j];
        }
        if(min > tmp) {
            min = tmp;
            minUser = i;
        }
    }
    return minUser;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> users >> rels;
    for(int i=1; i<=users; i++){
        for(int j=1; j<=users; j++){
            if(i==j){
                conn[i][j] = 0;
            } else {
                conn[i][j] = relMax;
            }                
        }
    }
    for(int i=0; i<rels; i++){
        int a, b;
        cin >> a >> b;
        conn[a][b] = 1;
        conn[b][a] = 1;
    }

    floyd();
    cout<<calcMin();
}
