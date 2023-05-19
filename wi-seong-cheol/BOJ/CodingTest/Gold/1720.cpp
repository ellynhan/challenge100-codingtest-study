//
//  1720.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/08.
//

/*
 [Input]
 4
 [Output]
 8
 */
// 시간복잡도: O(n)
// 최악시간: 30
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1720

#include <iostream>
#include <vector>

using namespace std;
#define ll long long
int n;
vector<ll> d(40, 0);         // 좌우 대칭과 무관하게 채우는 갯수
vector<ll> symmetric(40, 0); // 좌우 대칭인 형태의 갯수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    d[1] = 1;
    d[2] = 3;
    symmetric[1] = 1;
    symmetric[2] = 3;
    symmetric[3] = 1;
    symmetric[4] = 5;
    
    for (int i = 3; i <= n; ++i)
        d[i] = 2 * d[i - 2] + d[i - 1];
    for (int i = 5; i <= n; ++i)
        symmetric[i] = symmetric[i - 2] + 2 * symmetric[i - 4];
    
    cout << ((d[n] - symmetric[n]) / 2 + symmetric[n]);
    
    return 0;
}
