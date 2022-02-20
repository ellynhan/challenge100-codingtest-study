#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string s;
    unordered_set<string> heard;
    vector<string> hs;

    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        cin >> s;
        heard.insert(s);
    }

    for(int i=0; i<m; i++)
    {
        cin >> s;
        if(heard.find(s) != heard.end())
        {
            hs.push_back(s);
        }
    }

    cout << hs.size() << '\n';
    sort(hs.begin(), hs.end());
    for(int i=0; i<hs.size(); i++)
    {
        cout << hs[i] << '\n';
    }

    return 0;
}