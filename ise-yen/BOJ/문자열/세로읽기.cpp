#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    vector<string> v;
    int max = 0;
    for (int i = 0; i < 5; i++) {
        string str;
        cin >> str;
        v.push_back(str);
        if (max < str.length()) max = str.length();
    }

    string ans;

    for (int j = 0; j < max; j++) {
        for (int i = 0; i < 5; i++) {
            if (v[i].length() <= j) continue;
            ans += v[i][j];
        }
    }
    cout << ans;
    return 0;
}
