#include <bits/stdc++.h>

using namespace std;

list<int> l;

void parse_array(int n)
{
    string s;
    string digit;
    cin >> s;
    if(n == 0)
        return;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ',' || s[i] == ']') {
            l.push_back(stoi(digit));
            digit.clear();
        }
        else if(0x30 <= s[i] && s[i] <= 0x39)
            digit.push_back(s[i]);
    }
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    string cmd;
    bool is_reverse = false;
    bool is_error = false;

    cin >> t;

    for(int i=0; i<t; i++)
    {
        l.clear();
        cmd.clear();
        is_reverse = false;
        is_error = false;
        cin >> cmd >> n;
        parse_array(n);

        
        for(int j=0; j<cmd.size(); j++)
        {
            if(cmd[j] == 'R')
            {
                is_reverse = !is_reverse;
            }
            else if(l.empty())
            {
                is_error = true;
                break;
            }
            else if(is_reverse)
            {
                l.pop_back();
            }
            else if(!is_reverse)
            {
                l.pop_front();
            }
        }

        if(is_error)
        {
            cout << "error" << '\n';
            continue;
        }
        cout << '[';
        if (is_reverse)
        {
            while(!l.empty())
            {
                if(l.size() == 1)
                    cout << l.back();
                else
                    cout << l.back() << ',';
                l.pop_back();
            }
            
        }
        else
        {
            while (!l.empty())
            {
                if (l.size() == 1)
                    cout << l.front();
                else
                    cout << l.front() << ',';
                l.pop_front();
            }
        }
        cout << "]\n";
    }

    return 0;
}