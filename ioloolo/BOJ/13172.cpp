#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1'000'000'007;

ll M;
ll answer;

ll f(ll x, ll y) {
    if (y == 1) return x;
    if (y % 2 == 1) return x * f(x,y-1) % MOD;

    ll k = f(x, y/2);
    return k*k % MOD;
}

int main() {
    cin >> M;

    while (M--) {
        ll a, b;
        cin >> b >> a;

        ll g = gcd(a,b);
        b /= g;
        a /= g;

        answer += a * f(b, MOD-2) % MOD;
        answer %= MOD;
    }

    cout << answer;

    return 0;
}

