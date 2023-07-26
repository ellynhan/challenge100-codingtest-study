//
//  22866.cpp
//  main
//
//  Created by wi_seong on 2023/02/11.
//

/*
 [Input]
 8
 3 7 1 6 3 5 1 7
 [Output]
 1 2
 0
 3 2
 2 2
 4 4
 3 4
 4 6
 0
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/22866

#include <iostream>
#include <stack>

using namespace std;
int n, h[100001];
int L[100001];
int R[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<int> left, right;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
        while(!left.empty() && left.top() <= h[i])
            left.pop();
        L[i] = (int)left.size();
        left.push(h[i]);
    }
    for(int i = n - 1; i >= 0; i--) {
        while(!right.empty() && right.top() <= h[i])
            right.pop();
        R[i] = (int)right.size();
        right.push(h[i]);
    }
    
    for(int i = 0; i < n; i++) {
        if(L[i] + R[i] == 0) {
            cout << "0\n";
            continue;
        }
        cout << L[i] + R[i] << ' ';
        int l = i - 1;
        int r = i + 1;
        while(!(l < 0 && r >= n)) {
            if(l >= 0 && h[l] > h[i]) {
                cout << l + 1 << '\n';
                break;
            }
            if(r <= n && h[r] > h[i]) {
                cout << r + 1 << '\n';
                break;
            }
            l--;
            r++;
        }
    }
    
    return 0;
}
