#include <iostream>

using namespace std;
int DP[40][2];

int main()
{
    int T, N;
    cin >> T;
    DP[0][0] = 1; DP[0][1] = 0;
    DP[1][0] = 0; DP[1][1] = 1;
    for(int i=2; i<=40; i++){
        DP[i][0] = DP[i-1][0] + DP[i-2][0];
        DP[i][1] = DP[i-1][1] + DP[i-2][1];
    }
    while(T--){
        cin >> N;
        cout << DP[N][0] << ' ' << DP[N][1] << '\n';
    }
	return 0;
}
