//
//  6137.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/15.
//

/*
 [Input]
 161
 A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A A B
 [Output]
 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
 B
 */
// 시간복잡도: O(n^2)
// 최악시간: 4,000,000
// 난이도: Gold 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/6137

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
char ch;
vector<char> s, t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> ch;
        s.push_back(ch);
    }
    
    for(int i = 0; i < n; i++) {
        if(s.front() < s.back()) {
            t.push_back(s.front());
            s.erase(s.begin());
        } else if(s.front() > s.back()) {
            t.push_back(s.back());
            s.erase(s.end() - 1);
        } else {
            vector<char> tmp = s;
            reverse(tmp.begin(), tmp.end());
            int flag = 0;
            for(int j = 0; j < s.size()/2; j++) {
                if(tmp[j] != s[j]) {
                    flag = (tmp[j] < s[j]) + 1;
                    break;
                }
            }
            if(flag == 2) {
                t.push_back(s.back());
                s.erase(s.end() - 1);
            } else {
                t.push_back(s.front());
                s.erase(s.begin());
            }
        }
    }
    for(int i = 0; i < t.size(); i++) {
        if(i != 0 && i % 80 == 0) cout << '\n';
        cout << t[i];
    }
    
    return 0;
}
