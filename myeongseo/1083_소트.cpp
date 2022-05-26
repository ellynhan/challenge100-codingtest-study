#include <bits/stdc++.h>

using namespace std;

int N, e, S;
int element[50];

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> e;
        element[i] = e;
    }
    cin >> S;
}

void solve() {
    int cnt = 0, i=0, idx=0, val=0;
    // 남은 횟수동안에
    while(cnt<S && i<N) {
        idx = i;
        val = element[idx];
        // 앞쪽에 최대한 큰 수 배치
        for(int j=i+1; j<N; j++) {
            // i번째 수보다 크고 남은 횟수안에 이동 가능 할 때
            if(element[j]>element[i] && j-i<=S-cnt) {
                // 그중에서 가장 큰 수만 저장
                if(element[j]>element[idx])idx=j;
            }
        }
        val = element[idx];
        // i번째 수를 교환가능한 가장 큰수로 교환
        // i와 idx 사이는 한 칸씩 뒤로 밀려남
        for(int j=idx; j>i; j--) {
            element[j] = element[j-1];
        }
        element[i] = val;
        cnt += idx-i;
        // 다음 i번째 교체 시도
        i++;
    }
}

void output() {
    for(int i=0; i<N; i++) {
        cout << element[i] << endl;
    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}
