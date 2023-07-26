//
//  2668.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/05.
//

/*
 [Input]
 7
 3
 1
 1
 5
 5
 4
 6
 [Output]
 3
 1
 3
 5
 */
// 시간복잡도: O((n * m) * n)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2668

#include <iostream>
#include <set>
#include <cstring>

using namespace std;
set<int> ans;
int n;
bool isRight;
int input[101];
bool vis[101];

void dfs(int first, int num) {
    if(vis[num]) {
        if(first == num) {
            isRight = true;
            ans.insert(num);
        }
        return;
    }
    vis[num] = true;
    dfs(first, input[num]);
    if(isRight) {
        ans.insert(num);
        ans.insert(input[num]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> input[i];
        
    for(int i = 1; i <= n; i++) {
        memset(vis, false, sizeof(vis));
        vis[i] = true;
        isRight = false;
        dfs(i, input[i]);
    }
    cout << ans.size() << '\n';
    for(int x: ans)
        cout << x << '\n';
    
    return 0;
}
