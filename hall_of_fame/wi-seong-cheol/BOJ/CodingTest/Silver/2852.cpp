//
//  2852.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/13.
//

/*
 [Input]
 3
 1 01:10
 2 21:10
 2 31:30
 [Output]
 20:00
 16:30
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Silver 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2852

#include <iostream>
#include <string>

using namespace std;
int n, team;
int aTime, bTime, aScore, bScore;
string t, pre;

int s2i(string t) {
    int m = stoi(t.substr(0, 2));
    int s = stoi(t.substr(3, 2));
    return m * 60 + s;
}

string i2s(int t) {
    string ret = "";
    if(t / 60 < 10) ret += '0';
    ret += to_string(t/60) + ':';
    if(t % 60 < 10) ret += '0';
    ret += to_string(t % 60);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> team >> t;
        if(i != 0){
            if(aScore > bScore){
                aTime += s2i(t) - s2i(pre);
            } else if(aScore < bScore) {
                bTime += s2i(t) - s2i(pre);
            }
        }
        if(team == 1)
            aScore++;
        else
            bScore++;
        if(i == n - 1){
            if(aScore > bScore){
                aTime += s2i("48:00") - s2i(t);
            } else if(aScore < bScore) {
                bTime += s2i("48:00") - s2i(t);
            }
        }
        pre = t;
    }
    cout << i2s(aTime) << '\n' << i2s(bTime);
    
    return 0;
}
