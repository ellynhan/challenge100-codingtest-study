//
//  2250.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 19
 1 2 3
 2 4 5
 3 6 7
 4 8 -1
 5 9 10
 6 11 12
 7 13 -1
 8 -1 -1
 9 14 15
 10 -1 -1
 11 16 -1
 12 -1 -1
 13 17 -1
 14 -1 -1
 15 18 -1
 16 -1 -1
 17 -1 19
 18 -1 -1
 19 -1 -1
 [Output]
 3 18
 */
// 시간복잡도: O(n * m)
// 최악시간: 20,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2250

#include <iostream>
#include <vector>

using namespace std;
const int MX = 10001;
int n, colno, root, mxWidth, mxDepth;
int lc[MX], rc[MX];
pair<int, int> colLR[MX];
vector<bool> isRoot(10001, true);

void inorder(int cur, int d) {
    if(cur == -1) return;
    inorder(lc[cur], d + 1);
    colno++;
    auto &[lcol, rcol] = colLR[d];
    if(!lcol || colno < lcol) lcol = colno;
    if(!rcol || rcol < colno) rcol = colno;
    inorder(rc[cur], d + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int p, l, r;
        cin >> p >> l >> r;
        lc[p] = l;
        rc[p] = r;
        
        if(l != -1) isRoot[l] = false;
        if(r != -1) isRoot[r] = false;
    }
    for(int i = 1; i <= n; i++)
        if(isRoot[i]) {
            root = i;
            break;
        }
    inorder(root, 0);
    for(int d = 0; d < n; d++) {
        auto [lcol, rcol] = colLR[d];
        if (lcol + rcol == 0) break;
        int width = rcol - lcol + 1;
        if(mxWidth < width) {
            mxWidth = width;
            mxDepth = d;
        }
    }
    
    cout << mxDepth + 1 << ' ' << mxWidth;
    
    return 0;
}
