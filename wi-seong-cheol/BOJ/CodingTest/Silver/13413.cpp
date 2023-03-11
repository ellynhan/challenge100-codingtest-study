//
//  13413.cpp
//  main
//
//  Created by wi_seong on 2023/02/25.
//

/*
 [Input]
 3
 5
 WBBWW
 WBWBW
 7
 BBBBBBB
 BWBWBWB
 4
 WWBB
 BBWB
 [Output]
 1
 3
 2
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/13413

#include <iostream>
#include <algorithm>

using namespace std;
int t, n, cnt1, cnt2;
string a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        cnt1 = cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == 'W' && b[i] == 'B') cnt1++;
            if(a[i] == 'B' && b[i] == 'W') cnt2++;
        }
        cout << max(cnt1, cnt2) << '\n';
    }
    
    return 0;
}
