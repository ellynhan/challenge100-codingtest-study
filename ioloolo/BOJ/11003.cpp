#include <bits/stdc++.h>

using namespace std;

int N, L;
vector<int> arr;
deque<pair<int, int>> dq;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> L;
    arr.resize(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        if (!dq.empty() && dq.front().second < i - L + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && dq.back().first > arr[i]) {
            dq.pop_back();
        }

        dq.emplace_back(arr[i], i);

        cout << dq.front().first << " ";
    }


    return 0;
}

