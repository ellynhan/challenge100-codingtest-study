//
//  1991.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7
 A B C
 B D .
 C E F
 E . .
 F . G
 D . .
 G . .
 [Output]
 ABDCEFG
 DBAECFG
 DBEGFCA
 */
// 시간복잡도: O(n)
// 최악시간: 90
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1991

#include <iostream>

using namespace std;
int n;
int lc[30];
int rc[30];

void preorder(int cur) {
    cout << char(cur + 'A' - 1);
    if(lc[cur] != 0) preorder(lc[cur]);
    if(rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur) {
    if(lc[cur] != 0) inorder(lc[cur]);
    cout << char(cur + 'A' - 1);
    if(rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur) {
    if(lc[cur] != 0) postorder(lc[cur]);
    if(rc[cur] != 0) postorder(rc[cur]);
    cout << char(cur + 'A' - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c, l, r;
        cin >> c >> l >> r;
        if(l != '.') lc[c - 'A' + 1] = l - 'A' + 1;
        if(r != '.') rc[c - 'A' + 1] = r - 'A' + 1;
    }
    preorder(1); cout << '\n';
    inorder(1); cout << '\n';
    postorder(1); cout << '\n';
    
    return 0;
}
