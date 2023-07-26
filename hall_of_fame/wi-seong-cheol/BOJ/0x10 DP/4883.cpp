//
//  4883.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 4
 13 7 5
 7 13 6
 14 3 12
 15 6 16
 [Output]
 1. 22
 */
// 시간복잡도: O(n)
// 최악시간: 300,000
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/4883

#include <iostream>
#include <algorithm>

using namespace std;
int n, num;
int d[100001][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 3; j++)
                cin >> d[i][j];
        d[0][0] = 1001;
        d[0][2] += d[0][1];
        for(int i = 1; i < n; i++) {
            d[i][0] += min(d[i - 1][0], d[i - 1][1]);
            d[i][1] += min({d[i - 1][0], d[i - 1][1], d[i - 1][2], d[i][0]});
            d[i][2] += min({d[i - 1][1], d[i - 1][2], d[i][1]});
        }
        
        cout << ++num << ". " << d[n - 1][1] << '\n';
    }
    
    return 0;
}
