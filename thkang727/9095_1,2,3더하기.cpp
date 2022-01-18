*
    boj 9095
    dp
*/

#include <iostream>

using namespace std;

int main()
{
    int case_num,num;
    cin >> case_num;
    int dp[11];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 0 ; i<case_num;i++){
        cin >>num;
        if(num<11){
            for(int j = 4; j<=num;j++){
                dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
                //cout<< dp[j] << endl;
            }
        }
        cout<<dp[num] << endl;
    }

    return 0;
}
