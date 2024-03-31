#include <bits/stdc++.h>
using namespace std;

int a[500001];
int b[500001];
int c[500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    
    sort(a, a+N);
    for (int i = 0; i < M; i++) {
        int left = 0;
        int right = N - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] == b[i]) {
                c[i] = 1;
                break;
            } else if (a[mid] > b[i]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }            
        }
    }
    for (int i = 0; i < M; i++) {
        cout << c[i] << " ";
    }
}