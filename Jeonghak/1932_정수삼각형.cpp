#include<iostream>

using namespace std;
int DP[500][500];
int main()
{
    int N, result=0;
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            cin >> DP[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            if(j==0) DP[i][j] += DP[i-1][0];
            else if(i==j) DP[i][j] += DP[i-1][j-1];
            else DP[i][j] = max(DP[i-1][j-1] + DP[i][j], DP[i-1][j] + DP[i][j]);
            result = max(result, DP[i][j]);
        }
    }
    cout << result;
}