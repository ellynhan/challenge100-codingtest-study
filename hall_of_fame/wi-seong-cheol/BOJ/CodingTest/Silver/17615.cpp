//
//  17615.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/07.
//

/*
 [Input]
 9
 RBBBRBRRR
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 1,500,000
// 난이도: Silver 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/

#include <iostream>
#include <algorithm>

using namespace std;
int ans, cnt;
int n, redBallCnt, blueBallCnt;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    for(char ch: s) {
        if(ch == 'R') redBallCnt++;
        else blueBallCnt++;
    }
    ans = min(redBallCnt, blueBallCnt);
    
    // 2) 가장 왼쪽부터 연속된 색깔의 개수를 세어서 해당색의 전체개수에서 뺀다.
    //    기존의 답보다 작으면 갱신한다. (나머지 볼을 왼쪽으로 옮기는 경우)
    for(int i = 0; i < n; i++) {
        if(s[i] != s[0]) break;
        cnt++;
    }
    if(s[0] == 'R') ans = min(ans, redBallCnt - cnt);
    else ans = min(ans, blueBallCnt - cnt);
    
    // 3) 가장 오른쪽부터 연속된 색깔의 개수를 세어서 해당색의 전체개수에서 뺀다.
    //    기존의 답보다 작으면 갱신한다. (나머지 볼을 오른쪽으로 옮기는 경우)
    cnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] != s[n - 1]) break;
        cnt++;
    }
    
    if(s[n - 1] == 'R') ans = min(ans, redBallCnt - cnt);
    else ans = min(ans, blueBallCnt - cnt);
    
    cout << ans;
    
    return 0;
}
