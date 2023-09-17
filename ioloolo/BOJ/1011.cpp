#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        ll x, y;
        cin >> x >> y;

        ll max = 0;
        while(max*max <= y-x) {
            max++;
        }
        max--;

        ll move = 2*max -1;
        ll rem = y-x - max*max;

        rem = ceil((double) rem / (double) max);
        move += rem;

        cout << move << '\n';
    }

    return 0;
}

