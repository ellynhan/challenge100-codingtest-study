#include<iostream>
#include<vector>

using namespace std;

int T,N,result;

int main()
{
    cin >> T;
    while(T--)
    {
        vector<int> DP[2];
        cin >> N;
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<N; j++)
            {
                int n;
                cin >> n;
                DP[i].push_back(n);
            }
        }

        for(int i=2; i<N; i++){
            DP[0][i] += max(DP[1][i-2], DP[1][i-2] + DP[0][i-1]);
            DP[1][i] += max(DP[0][i-2], DP[1][i-2] + DP[0][i-1]);
            cout << DP[0][i] << ' ' << DP[1][i] << endl;
            result = max(DP[0][i], DP[1][i]);
        }
        
        cout << result;
    }
}
