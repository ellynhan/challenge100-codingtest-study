#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int T, reg, goal;
struct node{int num; string exe;};
vector<string> vec;
bool visited[10000];

void solve(int num, string exe){
    memset(visited, false, sizeof(visited));

    int next;
    node n;
    queue<node> q; q.push({num, exe});
    while(!q.empty()){
        n = q.front(); q.pop();
        num = n.num; exe = n.exe;

        next = (num * 2) % 10000;
        if(next == goal){
            vec.push_back(exe + "D");
            return;
        }
        if(!visited[next]){
            visited[next] = true;
            q.push({next, exe + "D"});
        }

        next = (num + 9999) % 10000;
        if(next == goal){
            vec.push_back(exe + "S");
            return;
        }
        if(!visited[next]){
            visited[next] = true;
            q.push({next, exe + "S"});
        }
        
        next = (num * 10) % 10000 + (num / 1000);
        if(next == goal){
            vec.push_back(exe + "L");
            return;
        }
        if(!visited[next]){
            visited[next] = true;
            q.push({next, exe + "L"});
        }
        
        next = (num / 10) + (num % 10) * 1000;
        if(next == goal){
            vec.push_back(exe + "R");
            return;
        }
        if(!visited[next]){
            visited[next] = true;
            q.push({next, exe + "R"});
        }
    }
}

int main(){
    cin >> T;
    while(T--){
        cin >> reg >> goal;

        solve(reg, "");
    }
    
    for(string s : vec) cout << s << "\n";
}
