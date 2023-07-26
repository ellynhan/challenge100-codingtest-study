//
//  23326.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 7
 0 1 0 0 1
 3
 1 2
 3
 2 9
 3
 1 5
 3
 [Output]
 1
 4
 0
 -1
 */
// 시간복잡도: O(Qlogn)
// 최악시간: 600,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/23326

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int n, q, type, x;
int cur = 1;
set<int> hu;  // 홍익대학교의 명소들 위치

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x) hu.insert(i);
    }
    
    while(q--) {
        cin >> type;
        switch (type) {
            case 1:
                cin >> x;
                if(hu.find(x) != hu.end())
                    hu.erase(x);
                else
                    hu.insert(x);
                break;
            case 2:
                cin >> x;
                cur = (cur + x - 1) % n + 1;
                break;
            case 3:
                if(hu.empty()) cout << "-1\n";
                else {
                    auto it = hu.lower_bound(cur);
                    if(it != hu.end())
                        cout << *it - cur << '\n';
                    else
                        cout << n - cur + *hu.begin() << '\n';
                }
                break;
            default:
                break;
        }
    }
    
    return 0;
}
