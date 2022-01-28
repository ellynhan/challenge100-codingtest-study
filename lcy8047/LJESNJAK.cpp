#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 0;
    string s;

    cin >> s;
    for( int i=0; i<s.size(); i++ ) {
        switch( s[i] )
        {
        case 'c':
            if( i < s.size()-1 && (s[i+1] == '=' || s[i+1] == '-') ) {
                count ++;
                i ++;
            }
            else {
                count ++;
            }
            break;
        case 'd':
            if( i < s.size()-1 && s[i+1] == '-' ) {
                count ++;
                i ++;
            } else if( i < s.size()-2 && s[i+1] == 'z' && s[i+2] == '=' ) {
                count ++;
                i += 2;
            }
            else {
                count ++;
            }
            break;
        case 'l':
        case 'n':
            if( i < s.size()-1 && s[i+1] == 'j' ) {
                count ++;
                i ++;
            }
            else {
                count ++;
            }
            break;
        case 's':
        case 'z':
            if( i < s.size()-1 && s[i+1] == '=' ) {
                count ++;
                i ++;
            }
            else {
                count ++;
            }
            break;
        default:
            count ++;
            break;
        }
    }

    cout << count << '\n';

    return 0;
}