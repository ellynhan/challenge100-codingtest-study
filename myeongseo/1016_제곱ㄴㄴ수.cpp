#include <bits/stdc++.h>

using namespace std;

long long minV, maxV;
long long power[1000001];

void input() {
    scanf("%lld %lld", &minV, &maxV);
}


void solve() {
    long long i = 2, j;
    while(i*i <= maxV) {

        j = minV / (i*i);        // 처음으로 나눠떨어지는 i*i의 배수 구하기
        if (minV % (i*i)) j++;

        while(i*i*j <= maxV){
            power[i*i*j - minV] = 1; // 제곱수로 나눠떨어지면 1로 표시하기
            j++;
        }
        i++;
    }
}


void output() {
    int result = 0;
    for(int k=0; k<maxV-minV+1; k++) {
        if(power[k] == 0) result++;  // 제곱수로 나눠떨어지지 않는 것의 개수
    }
    printf("%d\n", result);
}


int main() {
    input();
    solve();
    output();
    return 0;
}
