//
//  7662.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 2
 7
 I 16
 I -5643
 D -1
 D 1
 D 1
 I 123
 D -1
 9
 I -45
 I 653
 D 1
 I -642
 I 45
 I 97
 D 1
 D -1
 I 333
 [Output]
 EMPTY
 333 -45
 */
// 시간복잡도: O(nlogn)
// 최악시간: 6,000,000
// 난이도: Gold 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/7662

#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        multiset<int> ms;
        int n; cin >> n;
        while(n--) {
            char op;
            int x;
            cin >> op >> x;
            if(op == 'I') {
                ms.insert(x);
            } else {
                if(ms.empty()) continue;
                else if(x == 1)
                    ms.erase(prev(ms.end()));
                else
                    ms.erase(ms.begin());
            }
        }
        if(ms.empty()) cout << "EMPTY\n";
        else cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }
    
    return 0;
}
