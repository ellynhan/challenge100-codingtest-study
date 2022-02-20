// [BOJ] 숨바꼭질 / 실버1 / 1시간
// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

int N, K;
set<int> visited; // 방문한 좌표

void input(){
    cin >> N >> K;
}

int solve(){

    if(N == K){
        return 0; // 처음부터 같은 좌표였다면
    }

    int X;
    int walkLeft, walkRight, teleport;
    int step;
    
    queue<pair<int,int>> q; // 수빈이의 현재 좌표와 소요 시간 저장 queue
    q.push(make_pair(N,0));

    while(true)
    {
        X = q.front().first;
        step = q.front().second;
        q.pop();
        if(visited.find(X) != visited.end() || X < 0 || X > 100000){ // 방문한 좌표거나 범위를 벗어난 좌표면 무시
            continue;
        }
        visited.insert(X); // 방문 좌표 표시

        walkLeft = X - 1; // -1만큼 이동
        // cout << walkLeft << " ";
        if(walkLeft == K)
            return step+1;
        else
            q.push(make_pair(walkLeft,step+1));

        walkRight = X + 1; // +1만큼 이동
        // cout << walkRight << " ";
        if(walkRight == K)
            return step+1;
        else
            q.push(make_pair(walkRight,step+1));
        
        teleport = X * 2; // 순간이동!
        // cout << teleport << " ";
        if(teleport == K)
            return step+1;
        else
            q.push(make_pair(teleport,step+1));
    }
}

void print(){
    cout << solve();
}

int main(void){
    input();
    print();
}