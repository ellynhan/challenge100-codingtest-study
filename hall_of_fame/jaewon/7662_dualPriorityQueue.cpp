#include <iostream>
#include <queue>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
//0130 ~ 0250

struct bigger{
    bool operator()(pair<long long, int>& a, pair<long long, int>& b){
        return a.first < b.first;
    }
};

struct smaller{
    bool operator()(pair<long long, int>& a, pair<long long, int>& b){
        return a.first > b.first;
    }
};

int main(){
    ioboost;
    int T;
    cin >> T;
    while(T--){
        int k;
        long long n;
        char command;
        cin >> k;
        int check[1000000]={0};

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, bigger> pq_max;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, smaller> pq_min;

        for(int i=0; i<k; i++) {        
            cin >> command >> n;
            if(command == 'I') {
                pq_max.push({n,i});
                pq_min.push({n,i});
            } else if (n == 1) { //max
                while(!pq_max.empty() && check[pq_max.top().second]) pq_max.pop();
                if(!pq_max.empty()){
                    check[pq_max.top().second]=1;
                    pq_max.pop();
                }
            } else if (n == -1){ //min
                while(!pq_min.empty() && check[pq_min.top().second]) pq_min.pop();
                if(!pq_min.empty()){
                    check[pq_min.top().second]=1;
                    pq_min.pop();
                }
            }
        }

        while(!pq_min.empty() && check[pq_min.top().second]) pq_min.pop();
        while(!pq_max.empty() && check[pq_max.top().second]) pq_max.pop();

        if(pq_min.empty() || pq_max.empty()){
            cout<<"EMPTY\n";
        }else{
            cout<<pq_max.top().first<<" "<<pq_min.top().first<<'\n';
        }
    }
}