#include <bits/stdc++.h>

typedef unsigned long long ULL;

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    int n, t;
    int l, r;
    vector< pair<int,int> > result;
    int s_value = INT_MAX;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    l = 0;
    r = v.size()-1;
    while(l<r)
    {
        if(abs(v[l] + v[r]) < abs(s_value))
        {
            result.clear();
            result.emplace_back(v[l], v[r]);
            s_value = v[l] + v[r];
        }
        if( abs(v[l]) > abs(v[r]) )
            l ++;
        else
            r --;
    }

    cout << result[0].first << ' ' << result[0].second << '\n';

    return 0;
}
