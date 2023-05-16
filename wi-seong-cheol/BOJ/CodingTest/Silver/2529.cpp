//
//  2529.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/04.
//

/*
 [Input]
 2
 < >
 [Output]
 897
 021
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 1,024
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2529

#include <iostream>
#include <vector>

using namespace std;
int n;
bool ine[10];
bool isused[10];
vector<string> numbers;

void solve(int k, string s) {
    if(k == n + 1) {
        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(ine[i]) {
                if(s[i] > s[i + 1]) {
                    flag = false;
                    break;
                }
            } else {
                if(s[i] < s[i + 1]) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) numbers.push_back(s);
        return;
    }
    
    for(int i = 0; i < 10; i++) {
        if(!isused[i]) {
            isused[i] = true;
            solve(k + 1, s + to_string(i));
            isused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        char ch; cin >> ch;
        ine[i] = (ch == '<');
    }
    solve(0, "");
    cout << numbers.back() << '\n' << numbers.front();
    
    return 0;
}
