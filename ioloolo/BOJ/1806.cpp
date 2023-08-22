#include <bits/stdc++.h>

using namespace std;

int N, S;
int sum;
vector<int> arr;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> S;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int start = 0, end = 0;
    int minLen = 1e9;

    while (start <= end) {
        if (sum >= S) {
            minLen = min(minLen,end - start);
            sum -= arr[start++];
        } else if (end == N) {
            break;
        } else {
            sum += arr[end++];
        }
    }

    cout << (minLen == 1e9 ? 0 : minLen);

    return 0;
}

