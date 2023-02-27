//
//  1120.cpp
//  main
//
//  Created by wi_seong on 2023/02/27.
//

/*
 [Input]
 adaabc aababbc
 [Output]
 2
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 2,500
// 난이도: Silver 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1120

#include <iostream>
#include <algorithm>

using namespace std;
string a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b;
    int aLen = (int)a.size();
    int bLen = (int)b.size();
    int ans = aLen;
    for(int i = 0; i <= bLen - aLen; i++) {
        int dif = 0;
        for(int j = 0; j < aLen; j++)
            if(a[j] != b[i + j]) dif++;
        ans = min(ans, dif);
    }
    cout << ans;
    
    return 0;
}
