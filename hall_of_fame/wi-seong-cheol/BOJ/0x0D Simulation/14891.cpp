//
//  14891.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 10101111
 01111101
 11001110
 00000010
 2
 3 -1
 1 1
 [Output]
 7
 */
// 시간복잡도: O(k * n * m)
// 최악시간: 384
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/14891

#include <iostream>
#include <vector>

using namespace std;
int k;
vector<vector<char>> wheel(4);

void rotate(int n, int dir) {
    if(dir == -1) {
        char ch = wheel[n].front();
        wheel[n].erase(wheel[n].begin());
        wheel[n].push_back(ch);
    } else {
        char ch = wheel[n].back();
        wheel[n].pop_back();
        wheel[n].insert(wheel[n].begin(), ch);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    bool debug = true;
    for(int i = 0; i < 4; i++) {
        string s; cin >> s;
        for(auto ch: s) {
            wheel[i].push_back(ch);
        }
    }
    cin >> k;
    while(k--) {
        int n, dir;
        cin >> n >> dir;
        bool check[3];
        fill(check, check + 3, false);
        for(int i = 0; i < 3; i++)
            if(wheel[i][2] != wheel[i + 1][6])
                check[i] = true;
        if(n == 1) {
            rotate(n - 1, dir);
            if(check[0]) rotate(1, -dir);
            if(check[0] && check[1]) rotate(2, dir);
            if(check[0] && check[1] && check[2]) rotate(3, -dir);
        } else if(n == 2) {
            rotate(n - 1, dir);
            if(check[0]) rotate(0, -dir);
            if(check[1]) rotate(2, -dir);
            if(check[1] && check[2]) rotate(3, dir);
        } else if(n == 3) {
            rotate(n - 1, dir);
            if(check[0] && check[1]) rotate(0, dir);
            if(check[1]) rotate(1, -dir);
            if(check[2]) rotate(3, -dir);
        } else {
            rotate(n - 1, dir);
            if(check[0] && check[1] && check[2]) rotate(0, -dir);
            if(check[1] && check[2]) rotate(1, dir);
            if(check[2]) rotate(2, -dir);
        }
    }
    int ans = (wheel[0].front() == '1') ? 1 : 0;
    for(int i = 1; i < 4; i++)
        if(wheel[i].front() == '1')
            ans += (2 << (i - 1));
    
    cout << ans;
    return 0;
}
