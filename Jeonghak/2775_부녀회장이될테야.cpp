#include<iostream>
#define MAX_KN 15
using namespace std;
int DP[MAX_KN][MAX_KN];

void makeDP()
{
    for(int i=1; i<MAX_KN; i++) DP[0][i] = i;    
	for(int i=1; i<MAX_KN; i++){
		for(int j=1; j<MAX_KN; j++){
			DP[i][j] = DP[i-1][j] + DP[i][j-1];
		}
	}
}

int main()
{
    int T, K, N;
    cin >> T;
    makeDP();
    while(T--)
    {
        cin >> K >> N;
        cout << DP[K][N] << '\n';
    }
}
