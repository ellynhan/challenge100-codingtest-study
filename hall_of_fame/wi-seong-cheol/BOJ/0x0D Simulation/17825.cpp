//
//  17825.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 1 2 3 4 1 2 3 4 1 2
 [Output]
 190
 */
// 시간복잡도: O(4 ^ 10 * 10)
// 최악시간: 10,485,760
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17825

#include <iostream>
#include <algorithm>

using namespace std;
int ans;
int dice[10];   // 주사위의 입력값
int piece[4];   // 현재 말의 위치

int arr[34];    // 다음에 갈 위치 저장
int score[34];  // 윷놀이판 엔트리의 점수
int turn[34];   // 파란색 화살표가 있는 전환 지점
bool check[34]; // 윷놀이판 엔트리의 말 존재여부

void dfs(int cnt, int sum) {
    if(cnt == 10) {
        ans = max(ans, sum);
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int prev = piece[i];
        int cur = prev;
        int move = dice[cnt];
        
        if(turn[cur] > 0) {
            cur = turn[cur];
            move--;
        }
        
        while(move--) cur = arr[cur];
        
        if(cur != 21 && check[cur]) continue;
        
        check[prev] = false;
        check[cur] = true;
        piece[i] = cur;
        
        dfs(cnt + 1, sum + score[cur]); // 이동가능할 시, 해당 칸에 체크하고 점수추가해서 재귀 호출

        piece[i] = prev;
        check[prev] = true;
        check[cur] = false;
    }
}

void init(){
    for(int i = 0; i < 21; i++) arr[i] = i + 1;
    arr[21] = 21;
    
    for(int i = 22; i < 27; i++) arr[i] = i + 1;
    arr[27] = 20; arr[28] = 29; arr[29] = 30;
    arr[30] = 25; arr[31] = 32; arr[32] = 25;
    
    turn[5] = 22; turn[10] = 31; turn[15] = 28;
    
    for(int i = 0; i < 21; i++) score[i] = 2 * i;
    score[22] = 13; score[23] = 16; score[24] = 19;
    score[25] = 25; score[26] = 30; score[27] = 35;
    score[28] = 28; score[29] = 27; score[30] = 26;
    score[31] = 22; score[32] = 24;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    for(int i = 0; i < 10; i++)
        cin >> dice[i];
    dfs(0, 0);

    cout << ans;

    return 0;
}
