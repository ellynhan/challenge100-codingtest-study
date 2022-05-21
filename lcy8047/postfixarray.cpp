#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> postfix;
    string s;

    cin >> s;
    for( int i=0; i<s.size(); i++ ) {
        postfix.push_back( s.substr(i, s.size()-i) );
    }

    sort(postfix.begin(), postfix.end());

    for( int i=0; i<postfix.size(); i++ ) {
        cout << postfix[i] << '\n';
    }

    return 0;
}