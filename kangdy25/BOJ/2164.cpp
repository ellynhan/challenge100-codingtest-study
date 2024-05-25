// 카드2 / 실버 4

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    queue<int> q;
    bool check = true;
    
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    if (N == 1) {
        cout << "1\n";
    } else {
        while(q.size() != 1) {
            if (check) {
                q.pop();
                check = false;
            } else {
                q.push(q.front());
                q.pop();
                check = true;
            }
            N--;
        }
        cout << q.back() << "\n";
    }
}