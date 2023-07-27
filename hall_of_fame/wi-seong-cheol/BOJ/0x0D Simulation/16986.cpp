//
//  16986.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 3 2
 1 0 2
 2 1 0
 0 2 1
 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
 [Output]
 1
 */
// 시간복잡도: O(2^n)
// 최악시간: 1,048,576
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/16986

#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int board[10][10];
int friends[3][21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];
    for(int i = 1; i <= 2; i++)
        for(int j = 0; j < 20; j++)
            cin >> friends[i][j];
    for(int i = 0; i < 20; i++)
        friends[0][i] = i + 1;
    do {
        int w[3] = {0, 0, 0};
        int idx[3] = {0, 0, 0};
        int c1 = 0;
        int c2 = 1;
        
        while(1) {
            if(c1 > c2) swap(c1, c2);
            if(c1 == 0 && idx[0] >= n) break;
            int hand1 = friends[c1][idx[c1]++];
            int hand2 = friends[c2][idx[c2]++];
            if(board[hand1][hand2] == 2) {
                w[c1]++;
                if(w[c1] == k) break;
                c2 = 3-c1-c2;
            } else {
                w[c2]++;
                if(w[c2] == k) break;
                c1 = 3-c1-c2;
            }
        }
        
        if(w[0] == k) {
            cout << 1;
            return 0;
        }
    } while(next_permutation(friends[0], friends[0] + n));
    cout << 0;
    
    return 0;
}
