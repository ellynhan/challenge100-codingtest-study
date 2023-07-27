//
//  1790.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 20 23
 [Output]
 6
 */
// 시간복잡도: O()
// 최악시간:
// 난이도:
// Timer:
// Url: https://www.acmicpc.net/problem/1790

#include <iostream>

using namespace std;
int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    int x = 1;
    while(n--) {
        string s = to_string(x);
        int len = (int)s.length();
        if(len >= k) {
            cout << s[k - 1];
            return 0;
        }
        k -= len;
        x++;
    }
    cout << -1;
    
    return 0;
}
