//
//  14889.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(2^n * (n/2)^2)
// 최악시간: 104,857,600
// 난이도: Silver 2
// Timer: 20m
// Url: https://www.acmicpc.net/problem/14889

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int board[21][21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    vector<int> brute(n);
    fill(brute.begin() + (n / 2), brute.end(), 1);
    int ans = 0x7f7f7f7f;
    do {
        vector<int> teamA;
        vector<int> teamB;
        int sumA = 0;
        int sumB = 0;
        for(int i = 0; i < n; i++) {
            if(brute[i]) teamA.push_back(i);
            else teamB.push_back(i);
        }
        for(auto x: teamA) {
            for(auto y: teamA) {
                if(x == y) continue;
                sumA += board[x][y];
            }
        }
        for(auto x: teamB) {
            for(auto y: teamB) {
                if(x == y) continue;
                sumB += board[x][y];
            }
        }
        
        ans = min(ans, abs(sumA - sumB));
    } while(next_permutation(brute.begin(), brute.end()));
    cout << ans;
    
    return 0;
}
