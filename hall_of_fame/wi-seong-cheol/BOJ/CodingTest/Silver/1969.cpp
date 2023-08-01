//
//  1969.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/14.
//

/*
 [Input]
 5 8
 TATGATAC
 TAAGCTAC
 AAAGATCC
 TGAGATAC
 TAAGATGT
 [Output]
 TAAGATAC
 7
 */
// 시간복잡도: O(n * m)
// 최악시간: 4,000
// 난이도: Silver 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1969

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, cnt;
int s[1001][4];
string dna[1001];
string str;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> dna[i];
        for(int j = 0; j < m; j++) {
            char ch = dna[i][j];
            if(ch == 'A')
                s[j][0]++;
            else if(ch == 'C')
                s[j][1]++;
            else if(ch == 'G')
                s[j][2]++;
            else
                s[j][3]++;
        }
    }
    for(int i = 0; i < m; i++) {
        int mx = *max_element(s[i], s[i] + 4);
        if(mx == s[i][0])
            str += 'A';
        else if(mx == s[i][1])
            str += 'C';
        else if(mx == s[i][2])
            str += 'G';
        else
            str += 'T';
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(str[j] != dna[i][j])
                cnt++;
    cout << str << '\n' << cnt;
    
    return 0;
}
