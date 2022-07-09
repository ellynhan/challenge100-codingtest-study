#include<iostream>
#define MAX 1001

using namespace std;

string str1, str2;
int DP[MAX][MAX];

void find_LCS()
{
    for(int i=1; i<=str1.length(); i++){
        for(int j=1; j<=str2.length(); j++)
        {
            if(str1[i-1] == str2[j-1]) 
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }
}

int main()
{
    cin >> str1 >> str2;
    find_LCS();
    cout << DP[str1.length()][str2.length()];
}