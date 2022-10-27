#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int solve(int n)
{
    int l = 0;
    int h = v.size() - 1;
    int mid;
    while(l<=h)
    {
        mid = (h+l)/2;
        if(v[mid] == n)
        {
            return 1;
        }
        else if(v[mid] > n)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return 0;
}

int main(void)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    int t;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());

    cin >> m;
    for(int i=0; i<m; i++)
    {
        cin >> t;
        cout << solve(t) << '\n';
    }

    return 0;
}