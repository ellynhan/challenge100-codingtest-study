//
//  ITES.cpp
//  main
//
//  Created by wi_seong on 1/20/24.
//

/*
 [Input]
 3
 8791 20
 5265 5000
 3578452 5000000
 [Output]
 1
 4
 1049
 */
// 시간복잡도: O(n)
// 최악시간: 50,000,000
// 난이도: 중
// Timer: 40m
// Url: https://algospot.com/judge/problem/read/ITES

#include <iostream>
#include <queue>

using namespace std;
struct RNG {
    unsigned seed;
    RNG() : seed(1983) {}
    unsigned next() {
        unsigned ret = seed;
        seed = ((seed * 214013u) + 2531011u);
        return ret % 10000 + 1;
    }
};
int t, n, k;

int solve() {
    RNG rng;
    queue<int> range;
    int ret = 0, rangeSum = 0;

    for(int i = 0; i < n; i++) {
        int newSignal = rng.next();
        rangeSum += newSignal;
        range.push(newSignal);

        while(rangeSum > k) {
            rangeSum -= range.front();
            range.pop();
        }

        if(rangeSum == k) ret++;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> k >> n;
        cout << solve() << '\n';
    }

    return 0;
}
