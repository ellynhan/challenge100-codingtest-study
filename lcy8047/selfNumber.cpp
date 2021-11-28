#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool n[10001] = {false, };

    for(int i=1; i<10001; i++)
    {
        int t = i;
        while( t < 10000 )
        {
            int a = t;
            while(a != 0)
            {
                t += a%10;
                a /= 10;
            }
            if( t > 10000 || n[t] )
                break;
            n[t] = true;
        }
    }
    for(int i=1; i<10001; i++) {
        if(!n[i])
            cout << i << '\n';
    }
    return 0;
}