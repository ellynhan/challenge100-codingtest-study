#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string charCheck;
    string s;
    bool bIsGroupWord;
    int groupWordCount = 0;

    cin >> n;
    for( int i=0; i<n; i++ ) {
        cin >> s;

        bIsGroupWord = true;
        charCheck.clear();
        charCheck.push_back(s[0]);
        for( int j=1; j<s.size(); j++ ) {
            if( s[j-1] != s[j] && charCheck.find(s[j]) != string::npos ) {
                bIsGroupWord = false;
                break;
            }
            else {
                charCheck.push_back(s[j]);
            }
        }
        if( bIsGroupWord ) {
            groupWordCount ++;
        }
    }

    cout << groupWordCount << '\n';

    return 0;
}