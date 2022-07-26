//0336 ~ 0356 
#include <iostream>
using namespace std;

#define MAX_N 1000000
#define MAX_M 100000

int N, M;
int parent[MAX_N+1];

void init(){
    for(int i=0; i<=N; i++){
        parent[i] = i;
    }
}

int getParent(int child){
    if(parent[child] == child){
        return child;
    }else{
        parent[child] = getParent(parent[child]);
        return parent[child];
    }
}

bool isSameGroup(int g1, int g2){
    int p1 = getParent(g1);
    int p2 = getParent(g2);
    return p1 == p2;
}

void combine(int g1, int g2){
    int p1 = getParent(g1);
    int p2 = getParent(g2);
    if(p1 != p2){
        parent[p2] = p1;
    }
}

void print(bool ret){
    if(ret){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}

void input(){
    cin >> N >> M;
    init();
    for(int i=0; i<M; i ++){
        int cmd, g1, g2;
        cin >> cmd >> g1 >> g2;
        if(cmd == 0){ // 합침
            combine(g1,g2);
        }else{ // 같은 집합인지 확인
            print(isSameGroup(g1,g2));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
}