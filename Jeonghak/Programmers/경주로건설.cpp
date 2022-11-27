#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int min_cost = 0x7f7f7f7f;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Point {
    int x;
    int y;
};

void BFS(vector<vector<int>> board){
    queue<Point> q;
    q.push({0, 0});
    int straight=0, corner=0;
    int N = board.size();

    while(q.empty() == false){
        Point curr = q.front();
        q.pop();
        
        // 도착
        if(curr.x == N-1 && curr.y == N-1){
            int curr_cost = straight*100 + corner*500;
            cout << curr_cost;
            if(min_cost > curr_cost) min_cost = curr_cost;
            straight = 0;
            corner = 0;
        }
        
        for(int i=0; i<4; i++){
            Point next;
            next.x = curr.x + dx[i];
            next.y = curr.y + dy[i];
            if(next.x >=0 && next.x<N && next.y >=0 && next.y < N){
                q.push({next.x, next.y});
                // 직진
                if(dx[i] == 0) straight++;
                // 코너
                else corner++;
            }
        }
    }
    
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    BFS(board);
    return min_cost;
}

int main(){
    vector<vector<int>> board({{0,0,0},{0,0,0},{0,0,0}});
    solution(board);
}