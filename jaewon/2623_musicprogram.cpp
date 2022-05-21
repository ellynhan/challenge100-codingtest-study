#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

queue<int> order;
queue<int> answer;
set<int> front[1001];
set<int> back[1001];

int main(){
    ioboost;
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int num;
        cin >> num;
        if(num > 1){
            int prev, next;
            cin >> prev;
            for(int j=1; j<num; j++){
                cin >> next;
                back[prev].insert(next);
                front[next].insert(prev);
                if(front[prev].count(next)>0){
                    cout<<0;
                    return 0;
                }
                prev = next;             
            }
        }else if(num == 1){
            int throwaway;
            cin >> throwaway;
        }
    }

    for(int i=1; i<=n; i++){
        if(front[i].size()==0){
            order.push(i);
        }
    }

    while(!order.empty()){
        int curr = order.front();
        order.pop();
        answer.push(curr);
        set<int>::iterator it = back[curr].begin();
        for(; it!=back[curr].end(); it++){
            int next = *it;
            front[next].erase(curr);
            if(front[next].size()==0){
                order.push(next);
            }
        }
    }

    if(answer.size()!=n){cout<<0;} //ㅇㅣ게 왜.. 필요한거지??????
    else{
        while(!answer.empty()){
            cout<<answer.front()<<'\n';
            answer.pop();
        }
    }
}