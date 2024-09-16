// 제로 / 실버 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, num, total = 0;
    cin >> K;
    stack<int> money;

    while (K--) {
        cin >> num;
        if (num == 0) {
            money.pop();
        }
        else {
            money.push(num);
        }
    }

    while (!money.empty()) {
        total += money.top();
        money.pop();
    }
    cout << total << "\n";
}