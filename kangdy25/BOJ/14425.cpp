#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> a;
    vector<string> b;
    string input;
    int N, M, count = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> input;
        a.push_back(input);
    }

    for (int i = 0; i < M; i++) {
        cin >> input;
        b.push_back(input);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < b.size(); i++) {
        int left = 0;
        int right = a.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] == b[i]) {
                count++;
                break;
            }
            else if (a[mid] < b[i]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    cout << count << "\n";
}