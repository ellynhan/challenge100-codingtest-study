#include <bits/stdc++.h>

typedef unsigned long long ULL;

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    set<int> s;
    vector<int> input;
    unordered_map<int,int> m;
    vector<int> v;
    int i=0;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> t;
        input.push_back(t);
        s.emplace(t);
    }

    //sort(v.begin(), v.end());
    
    for(auto it = s.begin(); it != s.end(); it++, i++)
    {
        m[*it] = i;
    }

    for(int i=0; i<n; i++)
    {
        cout << m[input[i]];
        if(i == n-1)
            cout << '\n';
        else 
            cout << ' ';
    }

    return 0;
}