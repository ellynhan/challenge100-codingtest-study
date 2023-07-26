//
//  15721.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/14.
//

/*
 [Input]
 4
 6
 1
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Silver 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/15721

#include <iostream>

using namespace std;
int n, m, k;
int bbun, degi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    int round = 2;
    while(1) {
        for(int i = 0; i < 4; i++) {
            if(i % 2 == 0)
                bbun++;
            else
                degi++;
            if(k == 0) {
                if(bbun == m) {
                    cout << (bbun + degi - 1) % n;
                    return 0;
                }
            } else {
                if(degi == m) {
                    cout << (bbun + degi - 1) % n;
                    return 0;
                }
            }
        }
        
        for(int i = 0; i < round; i++) {
            bbun++;
            if(k == 0 && bbun == m) {
                cout << (bbun + degi - 1) % n;
                return 0;
            }
        }
        
        for(int i = 0; i < round; i++) {
            degi++;
            if(k == 1 && degi == m) {
                cout << (bbun + degi - 1) % n;
                return 0;
            }
        }
        round++;
    }
    
    return 0;
}
