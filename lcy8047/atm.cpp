#include <bits/stdc++.h>

typedef unsigned long long ULL;

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    ULL sum = 0;
    ULL cur_sum = 0;
    
    vector<int> v;
    
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        sum += cur_sum + v[i];
        cur_sum += v[i];
    }

    cout << sum << '\n';

    return 0;
}