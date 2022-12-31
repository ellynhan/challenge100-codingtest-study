#include <algorithm>
#include <deque>
#include <iostream>
#include <map>

using namespace std;

int main( void )
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    map<string, int> books;

    int n;
    int max = 0;
    cin >> n;
    for ( int i = 0; i < n; ++ i )
    {
        string name;
        cin >> name;
        books[name] ++;
        if ( books[name] > max )
        {
            max = books[name];
        }
    }

    for ( auto it : books )
    {
        if ( it.second == max )
        {
            cout << it.first << "\n";
            break;
        }
    }

    return 0;
}