#include<iostream>

using namespace std;

int DP[1025][1025];

int main()
{
    int N, M;
    int x1, x2, y1, y2;
    cin >> N >> M;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N; j++){
            cin >> DP[i][j];
            DP[i][j] += DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1];
        }
    }
    
    while(M--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << DP[x2][y2] - (DP[x1-1][y2] + DP[x2][y1-1] - DP[x1-1][y1-1]) << '\n';
    }
}
