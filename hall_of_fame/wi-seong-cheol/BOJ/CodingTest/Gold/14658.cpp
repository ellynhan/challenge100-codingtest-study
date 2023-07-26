//
//  14658.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 12 10 4 7
 2 4
 7 3
 3 1
 5 6
 4 7
 12 10
 8 6
 [Output]
 3
 */
// 시간복잡도: O(1,000,000)
// 최악시간: n ^ 3
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14658

#include <iostream>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int ans;
int n, m, l, k, x, y;
pair<int, int> star[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> l >> k;
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        star[i] = {x, y};
    }
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            int cnt = 0;
            for(int a = 0; a < k; a++) {
                if(star[i].X <= star[a].X && star[a].X <= star[i].X + l)
                    if(star[j].Y <= star[a].Y && star[a].Y <= star[j].Y + l)
                        cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << k - ans;
    
    return 0;
}
