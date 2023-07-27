//
//  2812.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/13.
//

/*
 [Input]
 10 4
 4177252841
 [Output]
 775841
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Gold 3
// Timer: 40m
// Url: https://www.acmicpc.net/problem/2812

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
int n, k;
string number;
vector<int> ans;
stack<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    cin >> number;
    
    int cnt = n - k;
    for(int i = 0; i < n; i++) {
        int x = number[i] - '0';
        while(!S.empty() && x > S.top()) {
            if(k == 0) break;
            S.pop();
            k--;
        }
        if(S.size() == cnt) continue;
        S.push(x);
    }
    while(!S.empty()) {
        ans.push_back(S.top());
        S.pop();
    }
    reverse(ans.begin(), ans.end());
    for(int x: ans)
        cout << x;
    
    return 0;
}
