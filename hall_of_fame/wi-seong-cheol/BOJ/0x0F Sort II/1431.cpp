//
//  1431.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/30.
//

/*
 [Input]
 5
 ABCD
 145C
 A
 A910
 Z321
 [Output]
 A
 ABCD
 Z321
 145C
 A910
 */
// 시간복잡도: O(nlogn)
// 최악시간: 85
// 난이도: Silver 3
// Timer: 9m
// Url: https://www.acmicpc.net/problem/1431

#include <iostream>
#include <algorithm>

using namespace std;
int n;
string arr[51];

bool cmp(const string& s1, const string& s2) {
    if(s1.length() != s2.length()) return s1.length() < s2.length();
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] >= '0' && s1[i] <= '9')
            cnt1 += s1[i] - '0';
        if(s2[i] >= '0' && s2[i] <= '9')
            cnt2 += s2[i] - '0';
    }
    if(cnt1 != cnt2) return cnt1 < cnt2;
    return s1 < s2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n, cmp);
    for(int i = 0; i < n; i++)
        cout << arr[i] << '\n';
    
    return 0;
}
