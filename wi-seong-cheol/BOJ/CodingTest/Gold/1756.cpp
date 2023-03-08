//
//  1756.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/08.
//

/*
 [Input]
 7 3
 5 6 4 3 6 2 3
 3 2 5
 [Output]
 2
 */
// 시간복잡도: O(nlogn)
// 최악시간: 1,500,000
// 난이도: Gold 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1756

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int oven[300001], dough[300001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    oven[0] = 0x7f7f7f7f;
    for(int i = 1; i <= n; i++) {
        cin >> oven[i];
        if(oven[i] > oven[i - 1])
            oven[i] = oven[i - 1];
    }
    for(int i = 1; i <= m; i++)
        cin >> dough[i];
    
    int pos = n + 1;    // 마지막 깊이
    int old;
    for(int i = 1; i <= m; i++) {
        old = dough[i - 1];
        if(!pos) break;
        if(dough[i] <= old) {
            pos--;
            continue;
        }
        int low = 0;
        int high = pos - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(dough[i] <= oven[mid]) {
                pos = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    cout << pos;
    
    return 0;
}
