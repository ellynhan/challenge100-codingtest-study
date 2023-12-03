#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isInMap(int r, int c){
    if(r >= 0 && c >= 0 && r < N && c < M) return true;
    else return false;
}

int bfs(int r, int c, int num, vector<vector<int>>& land){
    int cnt{};
    
    queue<pair<int, int>> q;
    q.push({r, c});
    cnt++;
    land[r][c] = num;
    
    while(!q.empty()){
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            
            if(!isInMap(nr, nc)) continue; // land를 벗어나면 패스
            if(land[nr][nc] > 1) continue; // 방문한 곳은 패스
            if(land[nr][nc] == 0) continue; // 석유가 아니면 패스

            q.push({nr, nc});
            cnt++;
            land[nr][nc] = num; // land 값을 직접 변경
        }
    }
    
    return cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;

    N = land.size();
    M = land[0].size();
    
    int num = 2; // 몇 번째 석유 덩어리인지(2번부터 카운트 : land의 디폴트가 1과 0이라서)
    vector<int> vRes; // 메모이제이션
    vRes.push_back(0); // 0번째 스킵용 인풋
    vRes.push_back(1); // 1번째 스킵용 인풋
    
    // 석유 덩어리별 크기 파악하기 + 메모이제이션
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(land[i][j] == 1){ // 탐색 안된 석유 덩어리라면
                // bfs 탐색
                int cnt = bfs(i, j, num, land); // 석유 크기 탐색
                vRes.push_back(cnt); // num번째 석유의 크기 = cnt
                num++;
            }
        }
    }

  // 석유 크기 계산
    for(int j = 0; j < M; j++){
        int res{}; // j열의 석유 크기 합계용
        vector<int> checkNv; // 서로 다른 석유인지 판단용
      
        // 시추관 투입
        for(int i = 0; i < N; i++){
            // 탐색 완료된 석유 덩어리라면
            if(land[i][j] > 1){
                int n = land[i][j]; // 석유 덩어리 번호

                // n이 checkNv에 있는지(이미 크기를 확인한 석유인지 체크용도)
                auto it = find(checkNv.begin(), checkNv.end(), n);
                // 체크한 적 없는 석유라면
                if(it == checkNv.end()){
                    checkNv.push_back(n); // 체크 용도에 넣기
                    res += vRes[n];
                }
            }
        }
        answer = max(answer, res);
    }
    
    return answer;
}
