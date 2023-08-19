#include <iostream>
#include <vector>

#define N ((int) (1e7+1))

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<bool> arr(N);
    fill(arr.begin(), arr.end(), true);
    arr[0] = arr[1] = false;
    for (int i = 2; i * i < N; ++i) {
        if (arr[i]) {
            for (int j = i*2; j <= N; j += i) {
                arr[j] = false;
            }
        }
    }

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        int result = 0;
        for (int i = 0; i <= n/2; ++i) {
            if (arr[i] && arr[n-i]) {
                result++;
            }
        }

        cout << result << '\n';
    }

    return 0;
}
