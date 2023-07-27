//
//  2164.cpp
//  main
//
//  Created by wi_seong on 2022/11/10.
//

/*
 [Input]
 6
 [Output]
 4
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Silver 4
// Timer: 2m
// Url: https://www.acmicpc.net/problem/2164

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    queue<int> Q;
    for(int i = 1; i <= n; i++)
        Q.push(i);
    while(Q.size() != 1) {
        Q.pop();
        int x = Q.front();
        Q.pop();
        Q.push(x);
    }
    cout << Q.front();
    
    return 0;
}
