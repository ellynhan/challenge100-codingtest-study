//
//  17281.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 2
 4 0 0 0 0 0 0 0 0
 4 0 0 0 0 0 0 0 0
 [Output]
 1
 */
// 시간복잡도: O((2 ^ n) * n)
// 최악시간: 51,200
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17281

#include <iostream>
#include <algorithm>

using namespace std;
int n, ans;
int a[51][10];
int order[9];

void run() {
    int score = 0;
    int idx = 0;
    
    for(int inning = 0; inning < n; inning++) {
        bool bases[4] = {};
        int out = 0;
        
        while(out < 3) {
            bases[0] = true;
            int move = a[inning][order[idx++]];
            if(idx == 9) idx = 0;
            if(!move) {
                out++;
                continue;
            }
            for(int i = 3; i >= 0; i--) {
                if(!bases[i]) continue;
                if(i + move >= 4) score++;
                else bases[i + move] = true;
                bases[i] = false;
            }
        }
    }
    ans = max(ans, score);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 9; j++)
            cin >> a[i][j];
    
    int arr[8];
    for(int i = 0; i < 8; i++)
        arr[i] = i + 1;
    order[3] = 0;
    
    do {
        copy(arr, arr + 3, order);
        copy(arr + 3, arr + 8, order + 4);
        run();
    } while (next_permutation(arr, arr + 8));
    cout << ans;
    
    return 0;
}
