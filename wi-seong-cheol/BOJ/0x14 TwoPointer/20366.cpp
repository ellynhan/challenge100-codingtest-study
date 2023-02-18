//
//  20366.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 3 5 2 5 9
 [Output]
 1
 */
// 시간복잡도: O(n^2)
// 최악시간: 360,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/20366

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> snow;

struct Elem { int index1, index2, sum; };

bool cmp(const Elem& a, const Elem& b) {
    return a.sum < b.sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        snow.push_back(x);
    }
    vector<Elem> snowman;
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            snowman.push_back({i, j, snow[i] + snow[j]});
    sort(snowman.begin(), snowman.end(), cmp);
    int ans = 0x7f7f7f7f;
    for(int i = 0; i < snowman.size() - 1; i++) {
        Elem anna = snowman[i];
        for(int j = i+1; j < snowman.size(); j++) {
            Elem elsa = snowman[j];
            if (elsa.index1 != anna.index1 &&
                elsa.index1 != anna.index2 &&
                elsa.index2 != anna.index1 &&
                elsa.index2 != anna.index2) {
                ans = min(ans, elsa.sum - anna.sum);
                break;
            }
        }
    }
    cout << ans;
    
    return 0;
}
