//
//  21925.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/13.
//

/*
 [Input]
 10
 1 1 5 6 7 7 6 5 5 5
 [Output]
 3
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 25,000,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/21925

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[5001];
int d[5001];

int evenPalindrome(int st) {
    if(st >= n) return 0;
    if(d[st] != 0) return d[st];
    
    int result = -1;
    
    for(int i = st + 1; i < n; i += 2) {
        bool isPalindrome = true;
        
        for(int j = 0; j <= (i - st) / 2; j++) {
            if(a[st + j] != a[i - j]) {
                isPalindrome = false;
                break;
            }
        }
        if(isPalindrome) {
            int val = evenPalindrome(i + 1);
            if(val == -1) continue;
            result = max(result, val + 1);
        }
    }
    
    return d[st] = result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << evenPalindrome(0);
    
    return 0;
}
