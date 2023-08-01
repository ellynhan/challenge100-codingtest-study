//
//  22945.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/10.
//

/*
 [Input]
 4
 1 4 2 5
 [Output]
 4
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/22945

#include <iostream>
#include <algorithm>

using namespace std;
int n, ans;
int a[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int st = 0;
    int en = n - 1;
    while(st <= en) {
        int between = en - st - 1;
        
        ans = max(ans, between * min(a[st], a[en]));
        
        if(a[st] < a[en]) st++;
        else en--;
    }
    
    cout << ans;
    
    return 0;
}
/*
 1 4 2 5
 
 1 4        -> 0
 1 4 2      -> 1
 1 4 2 5    -> 2
 4 2 5      -> 2
 2 5        -> 0
 */
