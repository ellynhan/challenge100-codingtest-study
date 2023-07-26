//
//  1943.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 2
 500 1
 50 1
 3
 100 2
 50 1
 10 5
 3
 1 1
 2 1
 3 1
 [Output]
 0
 1
 1
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1943

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n;
pair<int, int> coin[101];
bool d[50001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k = 3;
    while(k--) {
        int sum = 0;
        memset(d, false, sizeof(d));
        d[0] = true;
        
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> coin[i].X >> coin[i].Y;
            sum += coin[i].X * coin[i].Y;
        }
        if(sum % 2 != 0) {
            cout << "0\n";
            continue;
        }
        
        sort(coin, coin + n);
        
        for(int i = 0; i < n; i++) {
            for(int j = sum / 2; j >= coin[i].first; j--) {
                if(d[j - coin[i].X]) {
                    for(int k = 0; k < coin[i].Y; k++) {
                        if(j + k * coin[i].X > sum / 2) break;
                        d[j + k * coin[i].first] = true;
                    }
                }
            }
        }
        cout << d[sum / 2] << '\n';
    }
    
    return 0;
}
