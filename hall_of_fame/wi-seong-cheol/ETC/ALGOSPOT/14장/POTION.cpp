//
//  POTION.cpp
//  main
//
//  Created by wi_seong on 1/17/24.
//

/*
 [Input]
 3
 4
 4 6 2 4
 6 4 2 4
 4
 4 6 2 4
 7 4 2 4
 3
 4 5 6
 1 2 3
 [Output]
 0 5 1 2
 1 8 2 4
 3 3 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 3,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/POTION

#include <iostream>
#include <vector>

using namespace std;
int t, n;
vector<int> r, p;

void init() {
    r.clear();
    p.clear();
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

vector<int> solve(const vector<int>& recipe, const vector<int>& put) {
    int n = int(recipe.size());
    int b = recipe[0];

    for(int i = 1; i < n; i++)
        b = gcd(b, recipe[i]);
    int a = b;
    for(int i = 0; i < n; i++)
        a = max(a, ceil(put[i] * b, recipe[i]));

    vector<int> ret(n);
    for(int i = 0; i < n; i++)
        ret[i] = recipe[i] * a / b - put[i];

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        init();
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            r.push_back(x);
        }
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            p.push_back(x);
        }
        vector<int> ans = solve(r, p);
        for(int val: ans)
            cout << val << ' ';
        cout << '\n';
    }

	return 0;
}
