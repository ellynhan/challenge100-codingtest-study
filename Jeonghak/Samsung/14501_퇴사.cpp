#include<iostream>
#define MAX 17
using namespace std;

int T[MAX];
int P[MAX];
int DP[MAX];
int N;

void Input()
{
    int t, p;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> T[i] >> P[i];
    }
}

void Solve()
{
    for(int i=1; i<=N; i++){
        // i번째 상담을 하는 경우
        if(T[i] + i - 1 <= N){
            DP[i + T[i] - 1] = max(DP[i + T[i] - 1], DP[i-1] + P[i]);
        }
        // i 번째 상담을 하지 않는경우 이전까지 일한 최대 수당으로 갱신
        DP[i] = max(DP[i], DP[i - 1]);
    }
}

int main()
{
    Input();
    Solve();
    cout << DP[N];
    return 0;
}