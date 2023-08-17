#include <bits/stdc++.h>

#define MAX 1500000

using namespace std;

typedef struct {
    short date;
    short price;
} Info;

int N;
Info arr[MAX];
int dp[MAX];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i].date >> arr[i].price;

    int answer = 0, tmp = 0;

    for (int i = 0; i < N; ++i) {
        tmp = max(tmp, dp[i]);

        if (i + arr[i].date > N) continue;

        dp[i + arr[i].date] = max(dp[i + arr[i].date], tmp + arr[i].price);
        answer = max(answer, dp[i + arr[i].date]);
    }

    cout << answer;
}
