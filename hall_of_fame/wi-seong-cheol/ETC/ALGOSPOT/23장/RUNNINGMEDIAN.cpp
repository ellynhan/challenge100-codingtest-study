//
//  RUNNINGMEDIAN.cpp
//  main
//
//  Created by wi_seong on 1/23/24.
//

/*
 [Input]
 3
 10 1 0
 10 1 1
 10000 1273 4936
 [Output]
 19830
 19850
 2448920
 */
// 시간복잡도: O(nlogn)
// 최악시간: 1,000,000
// 난이도: 하
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/RUNNINGMEDIAN

#include <iostream>
#include <queue>

using namespace std;
const int MOD = 20090711;
struct RNG {
    int seed, a, b;
    RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
    int next() {
        int ret = seed;
        seed = ((seed * (long long)a) + b) % 20090711;
        return ret;
    }
};
int t, n, a, b;

int runningMedian() {
    int ret = 0;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    RNG rng(a, b);

    for(int i = 0; i < n; i++) {
        if(maxHeap.size() == minHeap.size())
            maxHeap.push(rng.next());
        else
            minHeap.push(rng.next());

        if(!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
            int a = maxHeap.top(), b = minHeap.top();
            maxHeap.pop(); minHeap.pop();
            maxHeap.push(b); minHeap.push(a);
        }

        ret = (ret + maxHeap.top()) % MOD;
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        cout << runningMedian() << '\n';
    }

	return 0;
}
