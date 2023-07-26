//
//  1062.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 9 8
 antabtica
 antaxtica
 antadtica
 antaetica
 antaftica
 antagtica
 antahtica
 antajtica
 antaktica
 [Output]
 3
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 67,108,864
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1062

#include <iostream>
#include <algorithm>

using namespace std;
int ans;
int n, k, teached;
int words[51];

void solve(int depth, int idx) {
    if(depth == k - 5) {
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if((words[i] & teached) == words[i])
                cnt++;
        ans = max(ans, cnt);
        return;
    }
    
    for(int i = idx; i < 26; i++) {
        if(teached & (1 << i)) continue;
        teached |= (1 << i);
        solve(depth + 1, i + 1);
        teached &= ~(1 << i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string w; cin >> w;
        for(char ch: w)
            words[i] |= 1 << (ch - 'a');
    }
    if(k < 5) {
        cout << 0;
        return 0;
    }
    teached |= 1 << ('a' - 'a');
    teached |= 1 << ('n' - 'a');
    teached |= 1 << ('t' - 'a');
    teached |= 1 << ('i' - 'a');
    teached |= 1 << ('c' - 'a');
    solve(0, 0);
    cout << ans;
    
    return 0;
}
