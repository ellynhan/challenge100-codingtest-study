//
//  1935.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/09.
//

/*
 [Input]
 1
 AA+A+
 1
 [Output]
 3.00
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1935

#include <iostream>
#include <stack>

using namespace std;
int n;
double arr[26];
string op;
stack<double> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> op;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(char ch: op) {
        if('A' <= ch && ch <= 'Z')
            S.push(arr[ch - 'A']);
        else {
            double b = S.top(); S.pop();
            double a = S.top(); S.pop();
            if(ch == '+') {
                S.push(a + b);
            } else if(ch == '-') {
                S.push(a - b);
            } else if(ch == '*') {
                S.push(a * b);
            } else {
                S.push(a / b);
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << S.top();
    
    return 0;
}
