//
//  1515.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/09.
//

/*
 [Input]
 1234
 [Output]
 4
 */
// 시간복잡도: O(n)
// 최악시간: 3,000
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1515

#include <iostream>
#include <string>

using namespace std;
int N;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    N = 1;
    string x = "";
    for(char ch: s) {
        while(1) {
            if(x == "")
                x = to_string(N++);
            if(x.front() == ch) {
                x.erase(x.begin());
                break;
            }
            x.erase(x.begin());
        }
    }
    cout << N - 1;
    
    return 0;
}
