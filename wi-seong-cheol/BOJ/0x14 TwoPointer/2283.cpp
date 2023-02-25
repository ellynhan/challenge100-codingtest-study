//
//  2283.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 25
 0 10
 3 15
 0 8
 3 10
 [Output]
 2 9
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2283

#include <iostream>

using namespace std;
int n, k, a, b, st, en, sum;
int num[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        for (int i = x+1; i <= y; i++) num[i]++;
    }
    
    while(1) {
        if(sum > k) sum -= num[++st];
        else if(en == 1000001) break;
        else sum += num[++en];
        
        if(sum == k) {
            a = st;
            b = en;
            break;
        }
    }
    
    cout << a << ' ' << b << '\n';
    
    return 0;
}
