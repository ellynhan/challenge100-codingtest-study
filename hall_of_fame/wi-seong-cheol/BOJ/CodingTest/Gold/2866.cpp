//
//  2866.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/16.
//

/*
 [Input]
 2 6
 dobarz
 adatak
 [Output]
 0
 */
// 시간복잡도: O(n^2)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/2866

#include <iostream>
#include <unordered_set>

using namespace std;
int r, c, ans;
string s[1001];
char board[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> board[i][j];
    for(int i = 0; i < c; i++) {
        string str = "";
        for(int j = 0; j < r; j++)
            str += board[j][i];
        s[i] = str;
    }
    
    for(int i = 1; i < c; i++) {
        unordered_set<string> st;
        for(int j = 0; j < c; j++) {
            string str = s[j].substr(i, c - i);
            st.insert(str);
        }
        if(st.size() != c) break;
        ans++;
    }
    cout << ans;
    
    return 0;
}
