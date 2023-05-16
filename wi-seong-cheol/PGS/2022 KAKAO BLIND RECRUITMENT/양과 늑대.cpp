//
//  양과 늑대.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/28.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 400
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92343

#include <string>
#include <vector>

using namespace std;

// 왼쪽 자식, 오른쪽 자식, 양/늑대 값
int l[20], r[20], val[20];
int n;
int ans = 1;
int vis[1<<17];

void dfs(int state){
    if(vis[state]) return;
    vis[state] = 1;
    // wolf : 늑대의 수, num : 전체 정점의 수
    int wolf = 0, num = 0;
    for(int i = 0; i < n; i++){
        if(state & (1 << i)){
            num++;
            wolf += val[i];
        }
    }
    // 만약 늑대가 절반 이상일 경우 방문할 수 없는 상태이니 종료
    if(2 * wolf >= num) return;
    // 현재 state의 양의 수가 ans보다 클 경우 ans를 갱신
    ans = max(ans, num - wolf);
    // 이제 다음 상태로 넘어갈 시간
    for(int i = 0; i < n; i++){
        // i번째 비트가 꺼져있는 경우 해당 정점이 없으니 넘어감
        if(!(state & (1 << i))) continue;
        // 현재 보고 있는 i번째 정점의 left가 있다면
        if(l[i] != -1)
            dfs(state | (1 << l[i]));
        // 현재 보고 있는 i번째 정점의 right가 있다면
        if(r[i] != -1)
            dfs(state | (1 << r[i]));
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    n = info.size();
    fill(l, l + n, -1);
    fill(r, r + n, -1);
    for(int i = 0; i < n; i++) val[i] = info[i];
    for(int i = 0; i < n - 1; i++){
        int a = edges[i][0];
        int b = edges[i][1];
        if(l[a] == -1) l[a] = b;
        else r[a] = b;
    }
    dfs(1);
    
    return ans;
}
