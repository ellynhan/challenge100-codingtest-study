#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int, vector<int>, less<int>> maxHeap;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){ 
        int tmp;
        cin >> tmp;
        if(minHeap.size() == maxHeap.size()){
            maxHeap.push(tmp);    
        }else{
            minHeap.push(tmp);
        }
        if(minHeap.size()>0&&minHeap.top()<maxHeap.top()){
            int swap = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(swap);
        }
        cout<<maxHeap.top()<<'\n';
    }
}
