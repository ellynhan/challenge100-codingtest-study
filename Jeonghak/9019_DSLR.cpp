#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int before, after;
bool visited[10000];

void solve()
{
    queue<pair<int, string>> q;
    q.push({before, ""});
    visited[before] = true;
    int currN, nextN;
    
    while(!q.empty())
    {
        currN = q.front().first;
        string op = q.front().second;
        q.pop();
        if(currN == after){
            cout << op << '\n';
            return;
        }
        nextN = currN*2%10000;
        if(!visited[nextN]){
            q.push({nextN, op + "D"});
            visited[nextN] = true;
        }
        nextN = currN - 1 < 0 ? 9999 : currN-1;
        if(!visited[nextN]){
            q.push({nextN, op + "S"});
            visited[nextN] = true;
        }
        nextN = (currN%1000)*10 + (currN/1000);
        if(!visited[nextN]){
            q.push({nextN, op + "L"});
            visited[nextN] = true;
        }
        nextN = currN/10 + (currN%10)*1000;
        if(!visited[nextN]){
            q.push({nextN, op + "R"});
            visited[nextN] = true;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        cin >> before >> after;
        memset(visited, false, sizeof(visited));
        solve();
    }
}
