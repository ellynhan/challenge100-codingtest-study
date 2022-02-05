#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main(){
    int count=0, T, docNum, target, prior;
    cin >> T;
    while(T--){
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        count=0;
        cin >> docNum >> target;
        for(int i=0; i<docNum; i++){
            cin >> prior;
            q.push(make_pair(i, prior));
            pq.push(prior);
        }
        while(!q.empty()){
            int idx = q.front().first;
            int curPrior = q.front().second;
            q.pop();
            if(pq.top() == curPrior){
                pq.pop();
                count++;
                if(idx == target){
                    cout << count << '\n';
                    break;
                } 
            }
            else q.push(make_pair(idx, curPrior));
        }
    }
}
