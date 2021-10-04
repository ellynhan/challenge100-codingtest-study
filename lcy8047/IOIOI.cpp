#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    char prev, cur;
    string s;
    int res = 0;
    int count = 0;

    cin >> n >> m >> s;
    prev = s[0];
    cur = prev;
    if(cur == 'I')
        count ++;
    for(int i=1; i<m; i++)
    {
        cur = s[i];
        if(cur == prev){
            if(count > n)
                res += count - n;
            count = 0;
        }
        if(cur == 'I')
            count ++;
        prev = cur;
    }
    if (count > n)
        res += count - n;

    cout << res << endl;


    return 0;
}