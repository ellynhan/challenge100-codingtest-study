#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> f;

ll fibo(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;

    if (f.count(n) > 0) return f[n];

    if (n % 2 == 0) {
        ll m = n / 2;
        ll a = fibo(m - 1);
        ll b = fibo(m);

        return f[n] = ((2 * a + b) * b) % 1'000'000'007;
    } else {
        ll m = (n + 1) / 2;
        ll a = fibo(m);
        ll b = fibo(m - 1);

        return f[n] = (a * a + b * b) % 1'000'000'007;
    }
    
}

int main() {
    ll n;

    cin >> n;
    cout << fibo(n);

    return 0;
}

