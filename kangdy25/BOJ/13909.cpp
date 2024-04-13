// 창문 닫기 / 실버 5

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, count = 0;
    cin >> N;
    
    for(int i = 1; i * i <= N; i++)
        count++;
    cout << count;
}