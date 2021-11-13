#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> a;
    vector<int> b;
    int res = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        b.push_back(t);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=0; i<n; i++)
    {
        res += a[i]*b[n-i-1];
    }
    cout << res << '\n';

    return 0;
}