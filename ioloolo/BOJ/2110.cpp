#include <bits/stdc++.h>

using namespace std;

int n, c;
int answer;
vector<int> pos;

int main() {
    cin >> n >> c;

    pos.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    sort(pos.begin(), pos.end());

    int start = 1;
    int end = pos[n - 1] - pos[0];
    int mid;

    while (start <= end) {
        int router = 1;
        int st = pos[0];

        mid = (start + end) / 2;

        for (int i = 1; i < n; i++) {
            if (pos[i] - st >= mid) {
                router++;
                st = pos[i];
            }
        }

        if (router >= c) {
            answer = max(answer, mid);
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}

