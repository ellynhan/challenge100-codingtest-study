//
//  4811.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 6
 1
 4
 2
 3
 30
 0
 [Output]
 132
 1
 14
 2
 5
 3814986502092304
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 900
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/4811

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
int n;
ll d[31][31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 31; i++)
        fill(d[i], d[i] + 31, 1);
    for(int w = 1; w < 31; w++) {
        for(int h = 0; h < 31; h++) {
            if(h == 0) {
                d[w][h] = d[w - 1][1];
            } else {
                d[w][h] = d[w - 1][h + 1] + d[w][h - 1];
            }
        }
    }
    
    while(1) {
        cin >> n;
        if(n == 0) break;
        cout << d[n - 1][1] << '\n';
    }
    
    return 0;
}
