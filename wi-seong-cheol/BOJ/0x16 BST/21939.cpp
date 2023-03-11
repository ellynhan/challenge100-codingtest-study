//
//  21939.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 1000 1
 1001 2
 19998 78
 2667 37
 2042 55
 8
 add 1402 59
 recommend 1
 solved 1000
 solved 19998
 recommend 1
 recommend -1
 solved 1001
 recommend -1
 [Output]
 19998
 1402
 1001
 2667
 */
// 시간복잡도: O(mlogn)
// 최악시간: 50,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/21939

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
int n, number, level, r, p;
string op;
int probLevel[100'002];
set<int> probByLevel[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        cin >> number >> level;
        probLevel[number] = level;
        probByLevel[level].insert(number);
    }
    cin >> n;
    while(n--) {
        string op; cin >> op;
        if(op[0] == 'a') {
            cin >> number >> level;
            probLevel[number] = level;
            probByLevel[level].insert(number);
        } else if(op[0] == 'r') {
            cin >> r;
            if(r == 1) {
                for(int i = 100; i >= 0; i--) {
                    if(probByLevel[i].empty()) continue;
                    cout << *(prev(probByLevel[i].end())) << '\n';
                    break;
                }
            } else {
                for(int i = 0; i <= 100; i++) {
                    if(probByLevel[i].empty()) continue;
                    cout << *probByLevel[i].begin() << '\n';
                    break;
                }
            }
        } else {
            cin >> p;
            probByLevel[probLevel[p]].erase(p);
        }
    }
    
    return 0;
}
