#include <iostream>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

//1228 ~ 47

int parent[500000];
int getParent(int a){
    if(parent[a] == a){
        return a;
    }else{
        return parent[a] = getParent(parent[a]);
    }
}

void unionFind(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a < b){
        parent[b]=a;
    }else{
        parent[a]=b;
    }
}

int findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b)return 1;
    return 0;
}


int main(){
    int n,m;
    cin >> n >> m;
    int answer = 0;
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    bool isDone = false;

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;

        if(findParent(x,y)!=1){
            unionFind(x,y);
        }else if(isDone == false){
            answer = i+1;
            isDone = true;
        }
    }
    cout<<answer;
}   