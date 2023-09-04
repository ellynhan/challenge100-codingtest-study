#include <bits/stdc++.h>

using namespace std;

int N, M;
int answer;
vector<bool> dis(10);

bool is_possible(int num) {
    string s = to_string(num);

    for (char i : s) {
        if (dis[i - 48]) {
            return false;
        }
    }

    return true;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int d;
        cin >> d;
        dis[d] = true;
    }

    if (N == 100) {
        cout << 0;
        return 0;
    }

    answer = abs(N - 100);

    for (int i = 0; i <= 1000000; i++) {
        if (is_possible(i)) {
            answer = min(answer, (int) (abs(N - i) + to_string(i).size()));
        }
    }

    cout << answer;

    return 0;
}

