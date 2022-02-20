#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int minN = INT_MAX;
    int maxN = 0;

    int n;
    int a;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> a;
        if( a < minN )
            minN = a;
        if( a > maxN )
            maxN = a;
    }

    cout << minN * maxN << '\n';

    return 0;
}