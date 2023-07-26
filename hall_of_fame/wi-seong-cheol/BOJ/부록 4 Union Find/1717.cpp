//
//  1717.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/27.
//

/*
 [Input]
 7 8
 0 1 3
 1 1 7
 0 7 6
 1 7 1
 0 3 7
 0 4 2
 0 1 1
 1 1 1
 [Output]
 NO
 NO
 YES
 */
// 시간복잡도: O(α(n) * n)
// 최악시간: 400,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1717

#include <iostream>

using namespace std;
int n, m, a, b, chk;
int parent[1000001];

int getParent(int x) {
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if(x < y) parent[y] = x;
    else parent[x] = y;
}

bool findParent(int x, int y) {
    return getParent(x) == getParent(y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        parent[i] = i;
    while(m--) {
        cin >> chk >> a >> b;
        if(chk) {
            if(findParent(a, b)) cout << "YES\n";
            else cout << "NO\n";
        } else {
            unionParent(a, b);
        }
    }
    
    return 0;
}
