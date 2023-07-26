//
//  13019.cpp
//  main
//
//  Created by wi_seong on 2023/02/10.
//

/*
 [Input]
 AAABBB
 BBBAAA
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 50
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/13019

#include <iostream>
#include <algorithm>

using namespace std;
string a, b;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b;
    
    int j = (int)b.length() - 1;
    for(int i = (int)a.size() - 1; i >= 0; i--) {
        if(a[i] != b[j])
            ans++;
        else
            j--;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a != b) cout << -1;
    else cout << ans;
    
    return 0;
}
