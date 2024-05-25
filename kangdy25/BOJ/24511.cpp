// queuestack / 실버 3

#include <bits/stdc++.h>
using namespace std;

int N, M, check, queuestack[100001];
deque<int> dq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> check;
        queuestack[i] = check;
    }
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (queuestack[i] == 0) {
            dq.push_back(x);
        }
    }
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        dq.push_front(x);
        cout << dq.back() << " ";
        dq.pop_back();
    }
    
}