//
//  17779.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 8
 1 2 3 4 5 6 7 8
 2 3 4 5 6 7 8 9
 3 4 5 6 7 8 9 1
 4 5 6 7 8 9 1 2
 5 6 7 8 9 1 2 3
 6 7 8 9 1 2 3 4
 7 8 9 1 2 3 4 5
 8 9 1 2 3 4 5 6
 [Output]
 24
 */
// 시간복잡도: O(n ^ 6)
// 최악시간: 64,000,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17779

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int INF = 0x7f7f7f7f;
int ans = INF;
int n;
int a[21][21];
int board[21][21];
pair<int, int> Pos[4];

void calculate() {
    int values[5] = {0, 0, 0, 0, 0};
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            values[board[i][j] - 1] += a[i][j];
    sort(values, values + 5);
    ans = min(ans, values[4] - values[0]);
}

bool canMakeLine(int x, int y, int d1, int d2){
    if(x + d1 >= n || y - d1 < 0) return false;
    if(x + d2 >= n || y + d2 >= n) return false;
    if(x + d1 + d2 >= n || y - d1 + d2 >= n) return false;
    if(x + d2 + d1 >= n || y + d2 - d1 < 0) return false;
 
    return true;
}

void division(int x, int y, int d1, int d2) {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            board[i][j] = 5;
     
    /* 1번 선거구 설정 과정.
     - 1번 선거구는 0행부터 1번 꼭짓점의 x좌표 행 까지
     - 1번 선거구는 0열부터 0번 꼭짓점의 y좌표 열 까지.
     - 이 과정에서 행의 값이, 0번 꼭짓점의 x좌표보다 크거나 같아지는 순간, 표시해야 하는 열의 갯수가 한칸씩 줄어든다. */
    int SubArea = 0;
    for(int i = 1; i < Pos[1].X; i++) {
        if (i >= Pos[0].X) SubArea++;
        for(int j = 1; j <= Pos[0].Y - SubArea; j++)
            board[i][j] = 1;
    }
     
    /* 2번 선거구 설정 과정.
     - 2번 선거구는 0행부터 2번 꼭짓점의 x좌표 행 까지.
     - 2번 선거구는 0번 꼭짓점의 y좌표 열 부터 맵의 끝까지.
     - 이 과정에서 행의 값이, 0번 꼭짓점의 x좌표 행보다 커지면, 표시해야 하는 열의 갯수가 한칸씩 줄어든다. */
    int PlusArea = 0;
    for(int i = 1; i <= Pos[2].X; i++){
        if(i > Pos[0].X) PlusArea++;
        for(int j = Pos[0].Y + 1 + PlusArea; j <= n; j++)
            board[i][j] = 2;
    }
    
    /* 3번 선거구 설정 과정.
     - 3번 선거구는 N - 1행부터 1번 꼭짓점의 x좌표 행까지.
     - 3번 선거구는 0열부터 3번 꼭짓점의 y좌표 열 까지.
     - 이 과정에서, 행의 값이 3번 꼭짓점의 x좌표 값보다 작아지면, 표시해야 하는 열의 갯수가 한칸씩 줄어든다.*/
    SubArea = 0;
    for(int i = n; i >= Pos[1].X; i--) {
        if(i < Pos[3].X) SubArea++;
        for(int j = 1; j < Pos[3].Y - SubArea; j++)
            board[i][j] = 3;
    }
    
    /* 4번 선거구 설정 과정.
     - 4번 선거구는 N - 1행부터 2번 꼭짓점의 x좌표 행까지.
     - 4번 선거구는 3번 꼭짓점의 y좌표 열부터, 맵의 끝까지.
     - 이 과정에서, 행의 값이 3번 꼭짓점의 x좌표 값보다 작아지면, 표시해야 하는 열의 갯수가 한칸씩 줄어든다. */
    PlusArea = 0;
    for(int i = n; i > Pos[2].X; i--) {
        if(i <= Pos[3].X) PlusArea++;
        for(int j = Pos[3].Y + PlusArea; j <= n; j++)
            board[i][j] = 4;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n; i++) {
        for(int j = 2; j <= n; j++) {
            for(int d1 = 1; d1 <= j; d1++) {
                for(int d2 = 1; d2 <= n - j; d2++) {
                    if(canMakeLine(i, j, d1, d2)) {
                        Pos[0].X = i;           Pos[0].Y = j;
                        Pos[1].X = i + d1;      Pos[1].Y = j - d1;
                        Pos[2].X = i + d2;      Pos[2].Y = j + d2;
                        Pos[3].X = i + d1 + d2; Pos[3].Y = j - d1 + d2;
                        division(i, j, d1, d2);
                        calculate();
                    }
                }
            }
        }
    }
    cout << ans;
    
    return 0;
}
