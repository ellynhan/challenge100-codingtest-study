#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j;
    string s;
    string t;
    vector<string> v;

    cin >> s;
    t = s;
    // 0~i-1 i~j-1 j~end
    for( int i=1; i<s.size() - 1; i++ ) {
        for( int j=i+1; j<s.size(); j++) {
            string s1 = s.substr(0, i);
            reverse(s1.begin(), s1.end());
            string s2 = s.substr(i, j-i);
            reverse(s2.begin(), s2.end());
            string s3 = s.substr(j, s.size()-j);
            reverse(s3.begin(), s3.end());
            v.push_back(s1+s2+s3);
        }
    }
    sort(v.begin(), v.end());

    cout << v[0] << '\n';

    return 0;
}