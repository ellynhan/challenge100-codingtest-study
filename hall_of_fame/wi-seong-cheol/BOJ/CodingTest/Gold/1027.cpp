//
//  1027.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 10
 1000000000 999999999 999999998 999999997 999999996 1 2 3 4 5
 [Output]
 6
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 250
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1027

#include <iostream>
#include <algorithm>

using namespace std;
int n, ans;
int h[51];
int cnt[51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int i = 0; i < n - 1; i++) {
        double maxGradient = -1000000000;

        for(int j = i + 1; j < n; j++) {
            int height = h[j] - h[i];
            int w = j - i;
            double g = height * 1.0 / w;

            if(g <= maxGradient) continue;

            maxGradient = g;
            cnt[i]++;
            cnt[j]++;
        }
    }
    cout << *max_element(cnt, cnt + n);;
    
    return 0;
}
