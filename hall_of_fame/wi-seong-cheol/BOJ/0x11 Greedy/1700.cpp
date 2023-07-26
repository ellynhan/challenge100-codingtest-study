//
//  1700.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 2 7
 2 3 2 3 1 2 7
 [Output]
 2
 */
// 시간복잡도: O(n^2)
// 최악시간: 10,000
// 난이도: Gold 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1700

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define Y second
int n, k, ans, cnt;
int a[101];
bool isused[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 1; i <= k; i++)
        cin >> a[i];
    for(int i = 1; i <= k; i++) {
        int cur = a[i];
        if(isused[cur]) continue;
        if(cnt < n) {
            isused[cur] = true;
            cnt++;
            continue;
        }
        vector<pair<int, int>> target;
        for(int x = 1; x <= k; x++) {
            if(!isused[x]) continue;
            bool vis = false;
            for(int y = i + 1; y <= k; y++) {
                if(a[y] == x) {
                    target.push_back({y, x});
                    vis = true;
                    break;
                }
            }
            if(!vis) target.push_back({k + 1, x});
        }
        sort(target.begin(), target.end(), greater<pair<int, int>>());
        int idx = target[0].Y;
        isused[idx] = false;
        isused[cur] = true;
        ans++;
    }
    cout << ans;
    
    return 0;
}
