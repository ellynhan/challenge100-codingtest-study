#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX_F 100000
#define MAX_LEN 20

int testCase, N;
int friends[MAX_F*2+1];
int sz[MAX_F*2+1];
unordered_map<string, int> nameIdx;
int nameCnt;

void init(){
    nameIdx.clear();
    nameCnt = 0;
    for(int i=0; i<=2*N; i++){
        friends[i] = i;
        sz[i] = 1;
    }
}

int getRoot(int idx){
    if(friends[idx] == idx){
        return idx;
    }else{
        return friends[idx] = getRoot(friends[idx]);
    }
}

void merge(int f1, int f2){
    int r1 = getRoot(f1);
    int r2 = getRoot(f2);
    if(r1 == r2){
        cout<<sz[r1]<<'\n';
        return;
    }
    if( r1 < r2){
        friends[r2] = r1;
        sz[r1] += sz[r2];
        cout<<sz[r1]<<'\n';
    }else{
        friends[r1] = r2;
        sz[r2] += sz[r1];
        cout<<sz[r2]<<'\n';
    }
}

void input(){
    cin >> N;
    init();
    string n1, n2;
    for(int i=0; i<N; i++){
        cin >> n1 >> n2;
        if(nameIdx.find(n1) == nameIdx.end()){
            nameIdx.insert({n1, nameCnt++});
        }
        if(nameIdx.find(n2) == nameIdx.end()){
            nameIdx.insert({n2, nameCnt++});
        }
        merge(nameIdx[n1], nameIdx[n2]);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> testCase;
    while(testCase--){
        input();
    }
}
