//
//  2503.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 2
 123 0 0
 456 0 0
 [Output]
 6
 */
// 시간복잡도: O(n)
// 최악시간: 270,000
// 난이도: Silver 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2503

#include <iostream>
#include <algorithm>

using namespace std;
int n, ans;
string number[101];
int strike[101];
int ball[101];
bool isNum[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> number[i] >> strike[i] >> ball[i];
    for(int i = 123; i <= 987; i++) {
        int x[3] = {i / 100, (i % 100) / 10, i % 10};
        bool flag = false;
        
        fill(isNum, isNum + 10, false);
        for(int j = 0; j < 3; j++) {
            if(x[j] == 0 || isNum[x[j]] == true) {
                flag = true;
                break;
            }
            isNum[x[j]] = true;
        }
        if(flag) continue;
        
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            int s = 0;
            int b = 0;
            for(int k = 0; k < 3; k++) {
                if(number[j][k] - '0' == x[k])
                    s++;
                else if(isNum[number[j][k] - '0'])
                    b++;
            }
            if(s == strike[j] && b == ball[j])
                cnt++;
            else
                break;
        }
        if(cnt == n) ans++;
    }
    cout << ans;
    
    return 0;
}
