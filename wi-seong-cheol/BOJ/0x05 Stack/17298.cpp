//
//  17298.cpp
//  main
//
//  Created by wi_seong on 2022/11/07.
//

/*
 [Input]
 4
 3 5 2 7
 [Output]
 5 7 7 -1
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Gold 4
// Timer: 18m
// Url: https://www.acmicpc.net/problem/17298

#include <iostream>
#include <stack>

using namespace std;
int n;
int arr[1000001];
int ans[1000001];
stack<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = n - 1; i >= 0; i--) {
        while(!S.empty() && S.top() <= arr[i])
            S.pop();
        if(S.empty()) ans[i] = -1;
        else ans[i] = S.top();
        S.push(arr[i]);
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    
    return 0;
}
