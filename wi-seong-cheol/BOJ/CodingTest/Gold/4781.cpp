//
//  4781.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 2 8.00
 700 7.00
 199 2.00
 3 8.00
 700 7.00
 299 3.00
 499 5.00
 0 0.00
 [Output]
 796
 798
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 50,000,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/4781

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m, cal;
double price;
int c[5001];
int p[5001];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        memset(c, 0, sizeof(c));
        memset(p, 0, sizeof(p));
        memset(d, 0, sizeof(d));
        
        cin >> n >> price;
        m = int(price * 100 + 0.5);
        if(n == 0 && m == 0) break;
        for(int i = 0; i < n; i++) {
            cin >> cal >> price;
            c[i] = cal;
            p[i] = int(price * 100 + 0.5);
        }
        
        for(int i = 1; i <= m; i++) {
            for(int j = 0; j < n; j++) {
                if(i >= p[j]) {
                    d[i] = max(d[i], d[i - p[j]] + c[j]);
                }
            }
        }
        cout << *max_element(d + 1, d + m + 1) << '\n';
    }
    
    return 0;
}
