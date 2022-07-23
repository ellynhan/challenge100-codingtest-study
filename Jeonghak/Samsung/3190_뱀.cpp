#include<iostream>
#include<queue>

using namespace std;
int N, K, L, Time;
int Map[101][101];
char curr_dir = 'R';
queue<pair<int, char>> trans_info;
queue<pair<int, int>>snake;

void Input()
{
    int tx, ty, t;
    char dir;
    cin >> N >> K;
    for(int i=0; i<K; i++)
    {
        cin >> ty >> tx;
        Map[ty][tx] = 1;
    }
    cin >> L;
    for(int i=0; i<L; i++){
        cin >> t >> dir;
        trans_info.push({t, dir});
    }
}

void Turnabout()
{
    // 왼쪽으로 90도
    if(trans_info.front().second == 'L'){
        if(curr_dir == 'R')
            curr_dir = 'U';
        else if(curr_dir == 'L')
            curr_dir = 'D';
        else if(curr_dir == 'U')
            curr_dir = 'L';
        else if(curr_dir == 'D')
            curr_dir = 'R';
    }
    // 오른쪽으로 90도
    else{
        if(curr_dir == 'R')
            curr_dir = 'D';
        else if(curr_dir == 'L')
            curr_dir = 'U';
        else if(curr_dir == 'U')
            curr_dir = 'R';
        else if(curr_dir == 'D')
            curr_dir = 'L';
    }
}

void Solve()
{
    snake.push({1, 1});
    int nx = 1, ny = 1;
    while(true)
    {
        Time++;
        // 다음 방문할 곳 
        if(curr_dir == 'U') ny--;
        else if(curr_dir == 'D') ny++;
        else if(curr_dir == 'R') nx++;
        else nx--;

        // 벽 또는 자기자신의 몸에 부딪히는 경우
        if(nx>N || ny>N || nx < 1 || ny < 1 || Map[ny][nx] == -1) 
            break;
        
        // 사과가 없는 경우
        if(Map[ny][nx] == 0)
        {
            // 꼬리 자르기
            Map[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }
        // 정상 범위인 경우 이동
        Map[ny][nx] = -1;
        snake.push({ny, nx});

        if(trans_info.front().first == Time){
            Turnabout();
            trans_info.pop();
        }
    }
}

int main()
{
    Input();
    Solve();
    cout << Time;
    return 0;
}