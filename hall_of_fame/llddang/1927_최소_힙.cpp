#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int N; cin >> N;
    int num;
    while(N--){
        cin >> num;
        if(num == 0){
            if(pq.empty()) cout << "0\n";
            else{ 
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(num);
        }
    }
}
