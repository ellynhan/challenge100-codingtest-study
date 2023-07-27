//
//  9375.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/08.
//

/*
 [Input]
 3
 2 3 5
 2
 4 5
 [Output]
 10
 */
// 시간복잡도: O(n^2)
// 최악시간: 1,000,000
// 난이도: Silver 1
// Timer: 40m
// Url: https://www.acmicpc.net/problem/9375

#include <iostream>
#include <numeric>

using namespace std;
#define ll long long
#define MX 1000000000
bool isBigger;
ll answer = 1;
int n, m, a[1001], b[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ll gc;
            if(a[i] < b[j]) {
                gc = gcd(a[i], b[j]);
            } else {
                gc = gcd(b[j], a[i]);
            }
            answer *= gc;
            a[i] /= gc;
            b[j] /= gc;
            if(answer >= MX) {
                answer %= MX;
                isBigger = true;
            }
        }
    }
    if(isBigger)
        printf("%09lld", answer);
    else
        cout << answer;
    
    return 0;
}
