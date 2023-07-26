//
//  2870.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/09.
//

/*
 [Input]
 4
 43silos0
 zita002
 le2sim
 231233
 [Output]
 0
 2
 2
 43
 231233
 */
// 시간복잡도: O(nlogn)
// 최악시간: 10,000
// 난이도: Silver 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2870

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<string> numbers;
string s;

bool cmp(string& a, string& b) {
    if(a.length() == b.length()) {
        for(int i = 0; i < a.length(); i++)
            if(a[i] != b[i])
                return a[i] < b[i];
    }
    return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        cin >> s;
        string x = "";
        for(char ch: s) {
            if('0' <= ch && ch <= '9') {
                x += ch;
            } else {
                if(x != "") {
                    while(x.size() >= 2 && x.front() == '0')
                        x.erase(x.begin());
                    numbers.push_back(x);
                    x = "";
                }
            }
        }
        if(x != "") {
            while(x.size() >= 2 && x.front() == '0')
                x.erase(x.begin());
            numbers.push_back(x);
        }
    }
    sort(numbers.begin(), numbers.end(), cmp);
    for(string x: numbers)
        cout << x << '\n';
    
    return 0;
}
