#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> deck;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        deck.push(tmp);
    }

    if (N == 1) {
        cout << 0;
        return 0;
    }

    int res = 0;

    while (deck.size() > 1) {
        int min1 = deck.top();
        deck.pop();

        int min2 = deck.top();
        deck.pop();

        res += min1 + min2;

        deck.push(min1 + min2);
    }

    cout << res;

    return 0;
}

