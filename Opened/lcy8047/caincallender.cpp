#include <bits/stdc++.h>

typedef unsigned long long ULL;

using namespace std;

int end_year(int m, int n)
{
    int temp;
    int n1 = m;
    int n2 = n;
    while(n2)
    {
        temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }
    return m * n / n1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int m, n, x, y;
    
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> m >> n >> x >> y;
        if(x == m)
            x = 0;
        if(y == n)
            y = 0;

        int endYear = end_year(m, n);
        int year;
        for (year = x; year <= endYear; year+=m)
        {
            if (year % n == y)
                break;
        }
        if (year > endYear)
            cout << -1 << '\n';
        else
            cout << year << '\n';
    }

    return 0;
}