#include <iostream>
#include <queue>

using namespace std;

struct compare{
    bool operator()(int a, int b){
        int A=a, B=b;
        if(a<0){
            A=-a;
        }
        if(b<0){
            B=-b;
        }
        if(A==B){
            return a>b;
        }else{
            return A>B;
        }
    }
};

priority_queue<int, vector<int>, compare> pq;
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x == 0){
            if(pq.empty()){
                cout<<0<<'\n';
            }else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }else{
            pq.push(x);
        }
    }
}
