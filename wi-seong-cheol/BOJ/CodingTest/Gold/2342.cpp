//
//  2342.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/03.
//

/*
 [Input]
 1 2 2 4 0
 [Output]
 8
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 2,500,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2342

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
int a[100001];
int d[5][5][100001];

int check(int from, int to){
    //처음에는 2
    if(from == 0) return 2;
    //다시 누르면 1
    if(from == to) return 1;
    //반대일 경우
    if(abs(from - to) == 2) return 4;
    //인접할 경우
    return 3;
}

int solve(int x, int y, int cur) {
    if(cur == n) return 0;
    if(d[x][y][cur] != -1) return d[x][y][cur];
    
    int left = solve(a[cur], y, cur + 1) + check(x, a[cur]);
    int right = solve(x, a[cur], cur + 1) + check(y, a[cur]);
    
    return d[x][y][cur] = min(left, right);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        int x; cin >> x;
        if(x == 0) break;
        a[n++] = x;
    }
    memset(d, -1, sizeof(d));
    cout << solve(0, 0, 0);
    
    return 0;
}
