#include<iostream>
using namespace std;

int main()
{
    int T, N, Max=0;
    cin >> T;
    int Q[100], DP[100];
    DP[0] = DP[1] = DP[2] = 1;
    for(int i=0; i<T; i++){
        cin >> N;
        Q[i] = N;
        Max = max(Max, N);
    }
    for(int i=3; i<Max; i++){
        DP[i] = DP[i-2] + DP[i-3];
    }
    for(int i=0; i<T; i++){
        cout << DP[Q[i]-1] << endl;
    }
}