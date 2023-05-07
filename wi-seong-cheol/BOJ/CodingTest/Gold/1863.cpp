//
//  1863.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/07.
//

/*
 [Input]
 10
 1 1
 2 2
 5 1
 6 3
 8 1
 11 0
 15 2
 17 3
 20 2
 22 1
 [Output]
 6
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 250,000,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1863

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int n;
int ans;
vector<int> height;
stack<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        height.push_back(y);
    }
    for(int i = 0; i < n; i++){
        int now = height[i];
        while(!S.empty() && S.top() > now){
            if(S.top()) ans++;
            S.pop();
        }
        if(!S.empty() && S.top() == now) continue;
        
        S.push(now);
    }
    while(!S.empty()){
        if(S.top()) ans++;
        S.pop();
    }
    cout << ans;
    
    return 0;
}
