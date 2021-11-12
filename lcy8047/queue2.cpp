#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int n;
    string command;
    queue<int> q;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> command;
        if( command.compare("push") == 0 ) {
            cin >> t;
            q.push(t);
        }
        else if (command.compare("pop") == 0) {
            if(q.empty())
                cout << "-1" << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (command.compare("size") == 0) {
            cout << q.size() << '\n';
        }
        else if (command.compare("empty") == 0) {
            if ( q.empty() )
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (command.compare("front") == 0) {
            if ( q.empty() )
                cout << "-1" << '\n';
            else {
                cout << q.front() << '\n';
            }
        }
        else if (command.compare("back") == 0) {
            if ( q.empty() )
                cout << "-1" << '\n';
            else {
                cout << q.back() << '\n';
            }
        }
    }

    return 0;
}