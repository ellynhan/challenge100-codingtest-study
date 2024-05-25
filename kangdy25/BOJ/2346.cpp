// 풍선 터뜨리기 / 실버 3

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, pop, coord, popTargetValue, popTargetCoord;
    cin >> N;
    deque<pair<int, int>> dq;

    for (int i = 1; i <= N; i++) {
        cin >> coord;
        dq.push_back(make_pair(coord, i));
    }

    while (!dq.empty()) {
        popTargetCoord = dq.front().first;
        popTargetValue = dq.front().second;

        cout << popTargetValue << " ";
        dq.pop_front();

        if (!dq.empty() && popTargetCoord > 0) {
            for (int i = 1; i < popTargetCoord; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else if (!dq.empty() && popTargetCoord < 0) {
            for (int i = 1; i < popTargetCoord * (-1) + 1; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}