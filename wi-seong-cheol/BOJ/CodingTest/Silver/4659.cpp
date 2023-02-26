//
//  4659.cpp
//  main
//
//  Created by wi_seong on 2023/02/10.
//

/*
 [Input]
 a
 tv
 ptoui
 bontres
 zoggax
 wiinq
 eep
 houctuh
 end
 [Output]
 <a> is acceptable.
 <tv> is not acceptable.
 <ptoui> is not acceptable.
 <bontres> is not acceptable.
 <zoggax> is not acceptable.
 <wiinq> is not acceptable.
 <eep> is acceptable.
 <houctuh> is acceptable.
 */
// 시간복잡도: O(n)
// 최악시간: 20
// 난이도: Silver 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/4659

#include <iostream>

using namespace std;
string s;
char gather[] = {'a', 'e', 'i', 'o', 'u'};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        cin >> s;
        if(s == "end") break;
        bool accept = true;
        bool isGather = false;
        int a = 0;  // 모음
        int b = 0;  // 자음
        for(int i = 0; i < s.size(); i++) {
            int type = 0;   // 모음: 1, 자음: 0
            
            for(char c: gather) {
                if(s[i] == c) {
                    isGather = true;
                    type = 1;
                }
            }
            if(type == 1) {
                a++;
                b = 0;
            }
            else {
                b++;
                a = 0;
            }
            
            // 규칙 2
            if(a >= 3 || b >= 3) {
                accept = false;
                break;
            }
            
            // 규칙 3
            if(i != 0 && s[i] == s[i - 1]) {
                if(s[i] == 'e' || s[i] == 'o')
                    continue;
                accept = false;
                break;
            }
        }
        // 규칙 1
        if(!isGather) accept = false;
        cout << '<' << s << '>';
        if(accept) cout << " is acceptable.\n";
        else cout << " is not acceptable.\n";
    }
    
    return 0;
}
