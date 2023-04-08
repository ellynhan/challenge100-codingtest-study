//
//  11723.cpp
//  main
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 26
 add 1
 add 2
 check 1
 check 2
 check 3
 remove 2
 check 1
 check 2
 toggle 3
 check 1
 check 2
 check 3
 check 4
 all
 check 10
 check 20
 toggle 10
 remove 20
 check 10
 check 20
 empty
 check 1
 toggle 1
 check 1
 toggle 1
 check 1
 [Output]
 1
 1
 0
 1
 0
 1
 0
 1
 0
 1
 1
 0
 0
 0
 1
 0
 */
// 시간복잡도: O(n)
// 최악시간: 3,000,000
// 난이도: Silver 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11723

#include <iostream>
#include <unordered_set>

using namespace std;
int n, x;
string op;
unordered_set<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        cin >> op;
        if(op == "add") {
            cin >> x;
            S.insert(x);
        } else if(op == "remove") {
            cin >> x;
            S.erase(x);
        } else if(op == "check") {
            cin >> x;
            cout << (S.find(x) != S.end()) << '\n';
        } else if(op == "toggle") {
            cin >> x;
            if(S.find(x) == S.end()) {
                S.insert(x);
            } else {
                S.erase(x);
            }
        } else if(op == "all") {
            for(int i = 1; i <= 20; i++)
                S.insert(i);
        } else if(op == "empty"){
            S.clear();
        }
    }
    return 0;
}
