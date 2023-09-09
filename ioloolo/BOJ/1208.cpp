#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, S;
ll cnt;
int arr[41];
map<int, int> psum;

void right(int mid, int sum){
    if (mid == N) {
        psum[sum]++;
        return;
    }

    right(mid + 1, sum + arr[mid]);
    right(mid + 1, sum);
}

void left(int start, int sum) {
    if (start == N / 2) {
        cnt += psum[S - sum];
        return;
    }

    left(start + 1, sum + arr[start]);
    left(start + 1, sum);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    right(N/2, 0);
    left(0, 0);

    cout << cnt - (!S ? 1 : 0);

    return 0;
}

