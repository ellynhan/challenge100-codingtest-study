//
//  1436.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(n * len(n))
// 최악시간: 70,000
// 난이도: Silver 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1436

#include <iostream>
#include <string>

using namespace std;
int n, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int cnt = 0;
    for(int i = 666; ; i++) {
        string num = to_string(i);
        for(int j = 0; j < num.size() - 2; j++) {
            if(num[j] == '6' && num[j + 1] == '6' && num[j + 2] == '6') {
                cnt++;
                break;
            }
        }
        if(cnt == n) {
            cout << i;
            break;
        }
    }
    
    return 0;
}
