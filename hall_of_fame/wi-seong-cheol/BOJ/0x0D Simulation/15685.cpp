//
//  15685.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 4
 3 3 0 1
 4 2 1 3
 4 2 2 1
 2 7 3 4
 [Output]
 11
 */
// 시간복잡도: O(n * m)
// 최악시간: 100,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/15685

#include <iostream>
#include <vector>

using namespace std;
int n, x, y, d, g, ans;
int board[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        cin >> x >> y >> d >> g;
        vector<int> v;
        v.push_back(d % 4);
        board[y][x] = 1;
        
        while(g--) {
            for(int j = (int)v.size() - 1; j >= 0; j--)
                v.push_back((v[j] + 1) % 4);
        }
        
        for(int i = 0; i < v.size(); i++){
            int dir = v[i];
            if(dir == 0) x++;
            else if(dir == 1) y--;
            else if(dir == 2) x--;
            else if(dir == 3) y++;
            board[y][x] = 1;
        }
    }
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(!board[i][j]) continue;
            if(board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) ans++;
        }
    }
    cout << ans;
    
    return 0;
}
