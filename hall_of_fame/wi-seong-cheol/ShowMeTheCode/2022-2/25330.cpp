//
//  25330.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/16.
//

/*
 [Input]
 5 5
 5 3 1 2 4
 10 10 10 10 10
 [Output]
 20
 */
// 시간복잡도: O(2^n)
// 최악시간: 1,048,576
// 난이도: Gold 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/25330

#include <iostream>
#include <algorithm>

using namespace std;
int n, k, ans;
int a[21];
int p[21];
bool isused[21];

void func(int used_hp, int path_sum, int people) {
    if(k - used_hp < 0) {
        return;
    }
    ans = max(ans, people);
    
    for(int i = 0; i < n; i++) {
        if(!isused[i]) {
            isused[i] = true;
            func(used_hp + path_sum + a[i], path_sum + a[i], people + p[i]);
            isused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> p[i];
    func(0, 0, 0);
    
    cout << ans;
    
    return 0;
}
