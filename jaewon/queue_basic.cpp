#include <iostream>
#include <queue>
using namespace std; 
int main(void) {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int numOfCmd;
    string cmd;
    cin >> numOfCmd;
    queue<int> q;
    while(numOfCmd--){
        cin >> cmd;
        if(cmd == "push"){
            int tmp;
            cin >> tmp;
            q.push(tmp);
        }else if(cmd == "front"){
            if(q.size()>0){
                cout<<q.front()<<'\n';
            }else{
                cout<<-1<<'\n';
            }
        }else if(cmd == "back"){
            if(q.size()>0){
                cout<<q.back()<<'\n';
            }else{
                cout<<-1<<'\n';
            }
        }else if(cmd == "size"){
            cout<<q.size()<<'\n';
        }else if(cmd == "empty"){
            if(q.empty()){
                cout<<1<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }else if(cmd == "pop"){
            if(q.size()>0){
                cout<<q.front()<<'\n';
                q.pop();
            }else{
                cout<<-1<<'\n';
            }
        }
    }
}
