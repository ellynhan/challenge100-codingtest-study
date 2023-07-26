//
//  6603.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 7 1 2 3 4 5 6 7
 8 1 2 3 5 8 13 21 34
 0
 [Output]
 1 2 3 4 5 6
 1 2 3 4 5 7
 1 2 3 4 6 7
 1 2 3 5 6 7
 1 2 4 5 6 7
 1 3 4 5 6 7
 2 3 4 5 6 7

 1 2 3 5 8 13
 1 2 3 5 8 21
 1 2 3 5 8 34
 1 2 3 5 13 21
 1 2 3 5 13 34
 1 2 3 5 21 34
 1 2 3 8 13 21
 1 2 3 8 13 34
 1 2 3 8 21 34
 1 2 3 13 21 34
 1 2 5 8 13 21
 1 2 5 8 13 34
 1 2 5 8 21 34
 1 2 5 13 21 34
 1 2 8 13 21 34
 1 3 5 8 13 21
 1 3 5 8 13 34
 1 3 5 8 21 34
 1 3 5 13 21 34
 1 3 8 13 21 34
 1 5 8 13 21 34
 2 3 5 8 13 21
 2 3 5 8 13 34
 2 3 5 8 21 34
 2 3 5 13 21 34
 2 3 8 13 21 34
 2 5 8 13 21 34
 3 5 8 13 21 34
 */
// 시간복잡도: O(n ^ n)
// 최악시간: 16,777,216
// 난이도: Silver 2
// Timer: 5m
// Url: https://www.acmicpc.net/problem/6603

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int board[14];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++)
            cin >> board[i];
        vector<bool> v;
        for(int i = 0; i < n; i++)
            v.push_back(i < 6 ? 0 : 1);
        do {
            for(int i = 0; i < n; i++)
                if(!v[i]) cout << board[i] << ' ';
            cout << '\n';
        } while(next_permutation(v.begin(), v.end()));
        cout << '\n';
    }
    return 0;
}
