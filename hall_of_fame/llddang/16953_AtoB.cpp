#include <iostream>
#include <queue>
using namespace std;

long long curr, goal;
queue<pair<int, int>> q;

long long bfs(){
    q.push({curr, 1});

    long long next, cnt;
    while(!q.empty()){
        curr = q.front().first; 
        cnt = q.front().second + 1; q.pop();

        next = curr * 10 + 1;
        if(next == goal) return cnt;
        if(next < goal) q.push({next, cnt});

        next = curr * 2;
        if(next == goal) return cnt;
        if(next < goal) q.push({next, cnt});
    }

    return -1;
}

int main(){
    cin >> curr >> goal;

    cout << bfs();
    return 0;
}
