#include<iostream>
#include<vector>
#define MAX_SIZE 8

using namespace std;
vector<pair<int, int>> cctv;
vector<vector<int>> office(MAX_SIZE, vector<int>(MAX_SIZE));

int N, M;
// 상, 우, 하, 좌
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int answer = 0x7f7f7f7f;

int countBlindSpot(){
    int result = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(office[i][j] == 0) result += 1;
        }
    } 
    return result;
}

void monitor(int x, int y, int dir) {
    int nx = x, ny = y;
    while(true) {
        nx += dx[dir];
        ny += dy[dir];
        if(nx < 0 || nx >= M || ny < 0 || ny >= N) break;
        if(office[ny][nx] == 6) break;
        if(office[ny][nx] == 0) office[ny][nx] = 7;
    }
    // print();
}

void initCopiedOffice(vector<vector<int>> &copiedOffice) {
    copiedOffice = office;
}

void initOffice(vector<vector<int>> copiedOffice) {
    office = copiedOffice;
}

void dfs(int depth) {
    if(depth == cctv.size()) {
        answer = min(answer, countBlindSpot());
        return;
    }
    // 변경 전 office 저장
    vector<vector<int>> copiedOffice;
    initCopiedOffice(copiedOffice);

    int y = cctv[depth].first;
    int x = cctv[depth].second;

    if(office[y][x] == 5){
        for(int i=0; i<4; i++) monitor(x, y, i);
        dfs(depth + 1);
        initOffice(copiedOffice);
    }    
    if(office[y][x] == 4){
        for(int i=0; i<4; i++) {
            monitor(x, y, (0 + i) % 4);
            monitor(x, y, (1 + i) % 4);
            monitor(x, y, (2 + i )% 4);
            dfs(depth + 1);
            initOffice(copiedOffice);
        }
    }
    if(office[y][x] == 3){
        for(int i=0; i<4; i++) {
            monitor(x, y, (0 + i) % 4);
            monitor(x, y, (1 + i) % 4);
            dfs(depth + 1);
            initOffice(copiedOffice);
        }
    }
    if(office[y][x] == 2){
        monitor(x, y, 0); monitor(x, y, 2);
        dfs(depth + 1);
        initOffice(copiedOffice);
        monitor(x, y, 1); monitor(x, y, 3);
        dfs(depth + 1);
        initOffice(copiedOffice);
    }
    if(office[y][x] == 1){
        for(int i=0; i<4; i++){
            monitor(x, y, i);
            dfs(depth + 1);
            initOffice(copiedOffice);
        }
    }
}

int main(void) {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> office[i][j];
            if(office[i][j] >= 1 && office[i][j] <= 5){
                cctv.push_back({i, j});
            }
        }
    }
    dfs(0);
    cout << answer;
}