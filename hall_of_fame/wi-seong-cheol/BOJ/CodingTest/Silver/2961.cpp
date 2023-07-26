//
//  2961.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/15.
//

/*
 [Input]
 1
 3 10
 [Output]
 7
 */
// 시간복잡도: O(n * 2^n)
// 최악시간: 10,240
// 난이도: Silver 2
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2961

#include <iostream>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int ans = 0x7f7f7f7f;
int n;
bool isused[11];
pair<int, int> a[11];

void func(int k, int sour, int bitter) {
    if(k > 0)
        ans = min(ans, abs(sour - bitter));
    if(k == n) return;
    for(int i = 0; i < n; i++) {
        if(!isused[i]) {
            isused[i] = true;
            func(k + 1, sour * a[i].X, bitter + a[i].Y);
            isused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;
    func(0, 1, 0);
    cout << ans;
    
    return 0;
}
