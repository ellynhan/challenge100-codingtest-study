#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef struct Info{
    double dist;
    int x,y;
    Info(double Dist, int X, int Y):dist(Dist),x(X),y(Y){}
}info;

struct compare{
    bool operator()(info& a, info& b){
        return a.dist > b.dist; //swap
    }  
};

priority_queue<info, vector<info>, compare> pq;
vector<pair<double, double>> stars;

int parent[101];

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}

int findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if( a == b ) return 1;
    return 0;
}

int main(){
    int n;
    cin >> n;
    double total = 0;
    for(int i=0; i<n; i++){
        double x,y;
        cin >> x >> y;
        stars.push_back({x,y});
        parent[i]=i;
    }   

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            double xDist = stars[i].first - stars[j].first;
            double yDist = stars[i].second - stars[j].second;
            double distance = sqrt(xDist*xDist + yDist*yDist);
            pq.push(info(distance, i,j));
        }
    }

    while(!pq.empty()){
        int x = pq.top().x;
        int y = pq.top().y;
        double dist = pq.top().dist;
        pq.pop();
        if(findParent(x,y)==1) continue;
        unionParent(x,y);
        total += dist;
    }

    
    printf("%.2f",total);
}
