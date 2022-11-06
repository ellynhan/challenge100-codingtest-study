//
//  1158.cpp
//  main
//
//  Created by wi_seong on 2022/11/06.
//

/*
 [Input]
 7 3
 [Output]
 <3, 6, 2, 7, 5, 1, 4>
 */
// 시간복잡도: O(nk)
// 최악시간: 25000000
// 난이도: Silver 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1158

#include <iostream>
#include <vector>

using namespace std;
int n, k, len;
int pre[5001], nxt[5001];
vector<int> v;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        pre[i] = (i == 1) ? n : i - 1;
        nxt[i] = (i == n) ? 1 : i + 1;
        len++;
    }
    int i = 1;
    for(int cur = 1; len != 0; cur = nxt[cur]) {
        if(i == k) {
            pre[nxt[cur]] = pre[cur];
            nxt[pre[cur]] = nxt[cur];
            v.push_back(cur);
            i = 1;
            len--;
        } else {
            i++;
        }
    }
    cout << '<';
    for(size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if(i != v.size() - 1) cout << ", ";
    }
    cout << '>';
    
    return 0;
}
