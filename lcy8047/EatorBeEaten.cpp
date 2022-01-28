#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int temp;
    int aSize, bSize;
    int bIdx;
    int res = 0;
    vector<int> a;
    vector<int> b;

    cin >> T;
    for( int testcase=0; testcase<T; testcase++ ) {
        a.clear();
        b.clear();
        res = 0;
        cin >> aSize >> bSize;
        for( int i=0; i<aSize; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        for( int i=0; i<bSize; i++) {
            cin >> temp;
            b.push_back(temp);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bIdx = bSize - 1;

        for( int i=aSize-1; i>=0; i-- ) {
            while( bIdx >= 0 && a[i] <= b[bIdx] ) {
                bIdx --;
            }
            if( bIdx < 0 )
                break;
            res += bIdx + 1;
        }
        cout << res << '\n';
    }

    return 0;
}