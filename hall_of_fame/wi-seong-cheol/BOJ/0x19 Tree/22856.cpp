//
//  22856.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7
 1 2 3
 2 4 5
 3 6 7
 4 -1 -1
 5 -1 -1
 6 -1 -1
 7 -1 -1
 [Output]
 10
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/22856

#include <iostream>

using namespace std;
const int MX = 100'001;
int root = 1;
int n, a, b, c, cnt, endpoint;
int parent[MX], lc[MX], rc[MX];
bool vis[MX];

void inorder(int cur) {
    cnt++;
    vis[cur] = true;
    if(lc[cur] != -1 && !vis[lc[cur]])
        inorder(lc[cur]);
    else if(rc[cur] != -1 && !vis[rc[cur]])
        inorder(rc[cur]);
    else {
        if(cur == endpoint) return;
        else inorder(parent[cur]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    parent[root] = -1;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        parent[b] = a;
        parent[c] = a;
        lc[a] = b;
        rc[a] = c;
    }
    endpoint = root;
    while(rc[endpoint] != -1)
        endpoint = rc[endpoint];
    inorder(root);
    cout << cnt - 1;
    
    return 0;
}
