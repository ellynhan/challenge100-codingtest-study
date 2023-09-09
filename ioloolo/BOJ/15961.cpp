#include <bits/stdc++.h>

using namespace std;

int N, d, k, c;
int answer;

int arr[3000001];

unordered_map<int, int> m;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < k - 1; i++) {
        m[arr[i]]++;
    }

    int tmp = k - 1;
    int start = 0;
    for(int i = 0 ; i < N ; i++){
        int curr = arr[tmp % N];
        int del = arr[start];

        m[curr]++;
        answer = max(answer, (int) m.size() + (m.find(c) == m.end() ? 1 : 0));
        m[del]--;

        if (m[del] == 0)
            m.erase(m.find(del));

        start++;
        tmp++;
    }

    cout << answer;
}

