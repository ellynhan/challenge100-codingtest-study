#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Conn{
    int a, b;
    Conn(int A, int B):a(A),b(B){}
}conn;

bool cmp(pair<int,Conn>&A, pair<int,Conn>&B){
    return A.first<B.first;
}
vector<pair<int, Conn>> vp;
int parents[10001];

int getParent(int x){
    if(parents[x]==x) return x;
    parents[x] = getParent(parents[x]);
    return parents[x]; 
}

void unionParent(int a, int b){
    int aP = getParent(a);
    int bP = getParent(b);
    if(aP<bP){
        parents[b]=aP;
        parents[bP]=aP;
    }else{
        parents[a]=bP;
        parents[aP]=bP;
    }
}

void updateParent(int a, int b){
    int aP = getParent(a);
    int bP = getParent(b);
    parents[a]=aP;
    parents[b]=bP;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int v,e;
    cin >> v >> e;
    for(int i=0; i<v; i++){
        parents[i+1]=i+1;
    }
    for(int i=0; i<e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        vp.push_back({c,Conn(a,b)}); 
    }  
    sort(vp.begin(), vp.end(),cmp);
    long long w = 0;

    for(int i=0; i<vp.size(); i++){
        int a = vp[i].second.a;
        int b = vp[i].second.b;
        updateParent(a,b);
        if(parents[a]!=parents[b]){
            w+=vp[i].first;
            unionParent(a,b);
        }
    }
    cout<<w;
}
