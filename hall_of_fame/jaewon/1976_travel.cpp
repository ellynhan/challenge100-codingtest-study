#include <iostream>
using namespace std;

#define MAX_N 200
#define MAX_M 1000

int N, M;
int conn[MAX_N+1][MAX_N+1];
int plan[MAX_M+1];
int parents[MAX_N+1];

int getParent(int a){
    if(parents[a] == a) return a;
    return parents[a] = getParent(parents[a]);
}

void combine(int a, int b){
    if(a < b){
        parents[b] = a;
    }else{
        parents[a] = b;
    }
}

void input(){
    cin >> N >> M;
    for(int i=0; i<=N; i++){
        parents[i] = i;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> conn[i][j];
            if(conn[i][j] == 0)continue;
            int p1 = getParent(i);
            int p2 = getParent(j);
            if(p1 != p2){
                combine(p1,p2);
            }
        }
    }
    for(int i=0; i<M; i++){
        cin >> plan[i];
    }
}

bool solve(){
    for(int i=0; i<M-1; i++){
        if(getParent(plan[i]) != getParent(plan[i+1])){
            return false;
        }
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    input();
    if(solve() && N > 0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}

