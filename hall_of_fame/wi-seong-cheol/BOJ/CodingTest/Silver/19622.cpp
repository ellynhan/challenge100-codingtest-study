//
//  19622.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/13.
//

/*
 [Input]
 6
 10 40 80
 30 60 60
 50 80 70
 70 100 100
 90 120 40
 110 140 50
 [Output]
 230
 */
// 시간복잡도: O(n)
// 최악시간: 100'000
// 난이도: Silver 2
// Timer: 20m
// Url: https://www.acmicpc.net/problem/19622

#include <iostream>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, people[100001], d[100001];
pair<int, int> t[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t[i].X >> t[i].Y >> people[i];
        d[i] = people[i];
    }
    for(int i = 1; i < n; i++) {
        d[i] = max(d[i], d[i - 1]);
        if(i >= 2)
            d[i] = max(d[i], people[i] + d[i - 2]);
    }
    cout << d[n - 1];
    
    return 0;
}
