//
//  1038.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 18
 [Output]
 42
 */
// 시간복잡도: O(1)
// 최악시간: 10,240
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1038

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
vector<ll> v;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i < 1024; i++) {
        ll num = 0;
        int tmp_i = i;
        
        for(int j = 9; j >= 0; j--) {
            if(tmp_i % 2 == 1)
                num = 10 * num + j;
            tmp_i /= 2;
        }
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    
    cin >> n;
    if(n > 1022) cout << -1;
    else cout << v[n];
    
    return 0;
}
