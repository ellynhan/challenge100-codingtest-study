#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int answer = 1e9;
bool selected[13];

vector<pii> house;
vector<pii> chicken;
vector<pii> picked;

void find_minimum(int x, int m) {
    if (m == M) {
        int result = 0;

        for (auto h : house) {
            int min_dist = 1e9;

            for (auto j : picked) {
                min_dist = min(min_dist, abs(h.first - j.first) + abs(h.second - j.second));
            }

            result += min_dist;
        }

        answer = min(answer, result);
    }

    for (int i = x; i < chicken.size(); i++) {
        if (selected[i]) continue;

        picked.emplace_back(chicken[i].first, chicken[i].second);

        selected[i] = true;
        find_minimum(i, m+1);
        selected[i] = false;

        picked.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;

            if (tmp == 1) {
                house.emplace_back(i, j);
            } else if (tmp == 2) {
                chicken.emplace_back(i, j);
            }
        }
    }

    find_minimum(0, 0);

    cout << answer;

    return 0;
}

