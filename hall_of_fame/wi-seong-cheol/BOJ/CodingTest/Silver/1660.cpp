//
//  1660.cpp
//  main
//
//  Created by wi_seong on 2023/02/10.
//

/*
 [Input]
 9
 [Output]
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 1,500,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1660

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;
const int SIZE = 300'001;
int n;
int a[SIZE];    // 삼각형을 만드는데 필요한 대포알의 갯수
int b[SIZE];    // 사면체를 만드는데 필요한 대포알의 갯수
int d[SIZE];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    fill(d, d + n + 1, INF);
    a[1] = 1;
    for(int i = 2; i <= n; i++)
        a[i] = a[i - 1] + i;
    b[1] = 1;
    for(int i = 2; i <= n; i++)
        b[i] = b[i - 1] + a[i];
    d[0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            if(b[j] > i) break;
            d[i] = min(d[i], d[i - b[j]] + 1);
        }
    cout << d[n];
    
    return 0;
}
