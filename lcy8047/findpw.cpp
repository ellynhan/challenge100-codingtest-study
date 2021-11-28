#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<string, string> site;

    int n, m;
    string s, p;
    cin >> n >> m;

    for(int i=0; i < n; i++) {
        cin >> s >> p;
        site.emplace(s, p);
    }

    for(int i=0; i < m; i++) {
        cin >> s;
        cout << site[s] << '\n';
    }

    return 0;
}