//
//  1106.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/08.
//

/*
 [Input]
 100 6
 4 9
 9 11
 3 4
 8 7
 1 2
 9 8
 [Output]
 45
 */
// 시간복잡도: O(n^2)
// 최악시간: 100,000,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1106

#include <iostream>
#include <algorithm>

using namespace std;
int c, n;
int cost[21];
int client[21];
int d[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> c >> n;
    for(int i = 1; i <= n; i++)
        cin >> cost[i] >> client[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 100000; j++)
            if(j - cost[i] >= 0)
                d[j] = max(d[j], d[j - cost[i]] + client[i]);
    for(int i = 1; i <= 100000; i++)
        if(d[i] >= c) {
            cout << i;
            break;
        }
    
    return 0;
}
