//
//  24337.cpp
//  main
//
//  Created by wi_seong on 2023/04/07.
//

/*
 [Input]
 9 1 5
 [Output]
 5 1 1 1 1 4 3 2 1
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/24337

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int n, a, b;
vector<int> ans;
stack<int> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> a >> b;
    int maxHeight = max(a, b);

    for(int i = 1; i < a; i++)
        ans.push_back(i);

    ans.push_back(maxHeight);

    for(int i = b - 1; i > 0; i--)
        ans.push_back(i);

    for(int i = 0; i <= ans.size(); i++) {
        if(!S.empty()) {
            if(S.size() == a || S.top() == 1) {
                for(int mid = 0; mid < n - (a + b) + 1; mid++)
                    ans.insert(ans.begin() + i, 1);
                break;
            }
            if(S.top() < ans[i])
                S.push(ans[i]);
        } else {
            S.push(ans[i]);
        }
    }

    if(ans.size() == n) {
        for(int x: ans)
            cout << x << " ";
    } else {
        cout << -1;
    }

    return 0;
}
