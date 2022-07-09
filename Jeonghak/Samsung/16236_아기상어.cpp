#include<iostream>
#include<queue>
#include<cstring>
#define MAX 21
using namespace std;

struct Point{
    int x;
    int y;
    int time;
    bool operator<(const Point& point) const {
        if (time == point.time) {
            // 같은 행일 때 왼쪽이 우선
            if (y == point.y) return x > point.x;
            // 위가 위선
            return y > point.y;
        }
        return time > point.time; 
    } 
};

int N, shark_size=2, eaten;
int result_time = 0;
Point start;
int space[MAX][MAX];
bool is_visited[MAX][MAX];
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

void Input()
{
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> space[i][j];
            if(space[i][j] == 9){
                start = {j, i, 0};
                space[i][j] = 0;
            }   
        }
    } 
}

void BFS()
{
    priority_queue<Point> pq;
    pq.push(start);

    while(!pq.empty()){
        Point curr = pq.top();
        pq.pop();
        // 물고기의 크기가 더 작거나 빈칸인 경우
        if(space[curr.y][curr.x] < shark_size){
            // 빈칸이 아닌 경우
            if(space[curr.y][curr.x] != 0){
                eaten++;                                         // 현재 먹은 물고기 수 증가
                space[curr.y][curr.x] = 0;                       // 빈칸으로 변경
                result_time += curr.time;                        // 총 시간 증가
                curr.time = 0;                                   // 현재 이동 시간 초기화
                memset(is_visited, false, sizeof(is_visited));   // 방문 표시 배열 초기화
                pq = priority_queue<Point>();                    // 방문할 q 초기화 
                pq.push(curr);                                   // 시작점을 현재 지점으로 하고 다시 BFS
                is_visited[curr.y][curr.x] = true;
            }
            // 상어 크기 증가, 현재 먹은 물고기 수 초기화
            if(eaten == shark_size){
                shark_size++;
                eaten =0;    
            }
        }
        for(int i = 0; i<4; i++){
            Point next;
            next.x = curr.x + dx[i];
            next.y = curr.y + dy[i];
            next.time = curr.time+1;
            // 범위 안이면
            if(next.x >= 0 && next.x < N && next.y >=0 && next.y < N){
                if(is_visited[next.y][next.x])
                    continue;
                // 물고기의 크기가 더 크면 방문하지 않는다.
                if(shark_size < space[next.y][next.x])
                    continue;
                pq.push(next);
                // 중복 방문 방지
                is_visited[next.y][next.x] = true;
            }
        }
    }
}

int main()
{
    Input();
    BFS();
    cout << result_time;
}