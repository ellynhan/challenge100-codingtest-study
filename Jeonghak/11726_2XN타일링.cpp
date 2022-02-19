#include<iostream>
using namespace std;
int *DP;
int main()
{
    int N;
    cin >> N;
    DP = new int[N+1];
    DP[1] = 1;
    DP[2] = 2;
    for(int i=3; i<=N; i++){
        DP[i] = (DP[i-1] + DP[i-2])%10007;
    }
    cout << DP[N];
}
