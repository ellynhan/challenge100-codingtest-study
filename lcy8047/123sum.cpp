#include <bits/stdc++.h>

using namespace std;


int s[4] = {0, };
int f[12] = {0, };

int fact(int n)
{
    int sum = 1;
    for(int i=2; i<=n; i++)
        sum *= i;
    
    return sum;
}

int calc_2(int n2, int n1)
{
    if (f[n2 + n1] == 0)
        f[n2 + n1] = fact(n2 + n1);
    if (f[n1] == 0)
        f[n1] = fact(n1);
    if (f[n2] == 0)
        f[n2] = fact(n2);
    return f[n2 + n1] / f[n1] / f[n2];
}

int calc_3(int n3, int n2, int n1)
{
    if (f[n3 + n2 + n1] == 0)
        f[n3 + n2 + n1] = fact(n3 + n2 + n1);
    if (f[n1] == 0)
        f[n1] = fact(n1);
    if (f[n2] == 0)
        f[n2] = fact(n2);
    if (f[n3] == 0)
        f[n3] = fact(n3);
    return f[n3 + n2 + n1] / f[n1] / f[n2]/f[n3];
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t, sum;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> t;

        sum = 1;
        s[1] = t-2;
        s[2] = 1;
        while(s[1] >= 0){
            sum += calc_2(s[2], s[1]);
            s[1] -= 2;
            s[2] ++;
        }
        
        s[2] = 0;
        int tmp = 1;
        s[1] = t-3*tmp;
        s[3] = 1;
        while(s[1] >= 0){
            s[2] = 0;
            while (s[1] >= 0)
            {
                sum += calc_3(s[3], s[2], s[1]);
                s[1] -= 2;
                s[2]++;
            }
            tmp ++;
            s[1] = t - 3 * tmp;
            s[3] ++;
        }

        cout << sum << '\n';
    }

    return 0;
}