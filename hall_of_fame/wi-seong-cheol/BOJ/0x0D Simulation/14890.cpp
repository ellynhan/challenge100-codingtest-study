//
//  14890.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 6 2
 3 2 1 1 2 3
 3 2 2 1 2 3
 3 2 2 2 3 3
 3 3 3 3 3 3
 3 3 3 3 2 2
 3 3 3 3 2 2
 [Output]
 7
 */
// 시간복잡도: O(2n * l)
// 최악시간: 20,000
// 난이도: Gold 3
// Timer: 40m
// Url: https://www.acmicpc.net/problem/14890

#include <iostream>
#include <vector>

using namespace std;
int n, k, ans;
int board[101][101];

int check(vector<int>& line) {
    int idx = 0;
    int cnt = 1;
    while(idx < n - 1) {
        if(abs(line[idx + 1] - line[idx]) > 1) return 0;
        if(line[idx] == line[idx + 1]) {
            idx++;
            cnt++;
        } else if(line[idx] < line[idx + 1]) {
            if (cnt < k) return 0;
            idx++;
            cnt = 1;
        } else {
            if(idx + k >= n) return 0;
            for(int i = idx + 1; i < idx + k; i++)
                if(line[i] != line[i + 1]) return 0;
            idx += k;
            cnt = 0;
        }
    }
    
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i< n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    for(int i = 0; i < n; i++) {
        vector<int> line;
        for(int j = 0; j < n; j++)
            line.push_back(board[i][j]);
        ans += check(line);
    }
    for(int i = 0; i < n; i++) {
        vector<int> line;
        for(int j = 0; j < n; j++)
            line.push_back(board[j][i]);
        ans += check(line);
    }
    cout << ans;
    
    return 0;
}
