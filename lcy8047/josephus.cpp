#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int cur_idx;
    bool *people;
    vector<int> sequence;

    cin >> n >> k;

    people = new bool[n];
    memset(people, true, n);

    cur_idx = k-1;
    while( true ) {
        sequence.push_back(cur_idx+1);
        people[cur_idx] = false;

        if( sequence.size() == n )
            break;

        for( int i=0; i<k; i++) {
            cur_idx = (cur_idx + 1) % n;
            while( !people[cur_idx] )
                cur_idx = (cur_idx + 1) % n;
        }
    }

    cout << "<";
    for( int i=0; i<n-1; i++) {
        cout << sequence[i] << ", ";
    }
    cout << sequence.back() << ">\n";
    return 0;
}