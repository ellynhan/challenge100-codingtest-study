//
//  2531.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 8 30 4 30
 7
 9
 7
 30
 2
 7
 9
 25
 [Output]
 5
 */
// 시간복잡도: O(n)
// 최악시간: 30,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2531

#include <iostream>
#include <algorithm>

using namespace std;
int n, d, k, c;
int ans, cnt;
int a[30001];
int check[3001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int left = 0;
    int right = k - 1;
    for(int i = 0; i < k; i++) {
        check[a[i]]++;
        if(check[a[i]] == 1)
            cnt++;
    }
    check[c]++;
    if(check[c] == 1) cnt++;
    
    while(left < n) {
        ans = max(ans, cnt);
        if(--check[a[left++]] == 0) cnt--;
        right = (right+1) % n;
        if(++check[a[right]] == 1) cnt++;
    }
    
    cout << ans;
    
    return 0;
}
