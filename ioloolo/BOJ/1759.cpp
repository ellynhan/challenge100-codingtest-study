#include <bits/stdc++.h>
#include <utility>

using namespace std;

int L, C;
vector<char> v;

typedef struct {
    int now;
    int consonant;
    int vowel;
    string str;
} Info;

void dfs(Info info){
    auto [now, consonant, vowel, str] = std::move(info);

    str.push_back(v[now]);

    v[now] == 'a' || v[now] == 'e' || v[now] == 'i' || v[now] == 'o' || v[now] == 'u'
    ? vowel++
    : consonant++;

    if (str.length() == L) {
        if(vowel >= 1 && consonant >= 2) {
            cout << str << '\n';
        }

        return;
    }

    for (int i = now + 1; i < C; i++) {
        dfs({i, consonant, vowel, str});
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> L >> C;

    v.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i <= C - L; i++) {
        dfs({i, 0, 0, ""});
    }

    return 0;
}

