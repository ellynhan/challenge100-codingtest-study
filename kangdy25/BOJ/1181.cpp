#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; 
    cin >> N;
    string s;
    vector<string> word;
    
    for (int i = 0; i < N; i++) {
        cin >> s;
        word.push_back(s);
    }
    
    sort(word.begin(), word.end(), compare);
    word.erase(unique(word.begin(), word.end()), word.end());
    
    for (int i = 0; i < word.size(); i++) {
        cout << word[i] << "\n";
    }
}