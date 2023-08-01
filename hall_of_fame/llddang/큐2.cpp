#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N; cin >> N;
    
    queue<int> ue;
    int tp;
    string tmp; 
    
    while(N--){
        cin >> tmp;
        if(tmp == "push"){
            cin >> tp;
            ue.push(tp);
        } else if(tmp == "pop"){
            if(!ue.empty()){
                cout << ue.front() << "\n";
                ue.pop();
            }
            else            cout << "-1\n";
        } else if(tmp == "size"){
            cout << ue.size() << "\n";
        } else if(tmp == "empty"){
            if(!ue.empty()) cout << "0\n";
            else            cout << "1\n";
        } else if(tmp == "front"){
            if(!ue.empty()) cout << ue.front() << "\n";
            else            cout << "-1\n";
        } else if(tmp == "back"){
            if(!ue.empty()) cout << ue.back() << "\n";
            else            cout << "-1\n";
        }
    }
}
