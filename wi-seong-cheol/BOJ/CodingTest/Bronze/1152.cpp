//
//  1152.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/24.
//

/*
 [Input]
 The last character is a blank
 [Output]
 6
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Bronze 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1152

#include <iostream>
#include <sstream>

using namespace std;
int ans;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    getline(cin, s);
    stringstream ss(s);
    string token;
    while(getline(ss, token, ' ')) {
        if(token != "") ans++;
    }
    cout << ans;
    
    return 0;
}
