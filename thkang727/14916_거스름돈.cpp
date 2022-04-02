/*
    14916
    실버5 수학
*/


#include <iostream>

using namespace std;

int main()
{
    int n,ans=0;
    cin >> n;

    int divn = n/5 , modn = n%5;

    if(modn%2==1){
        divn--;
        modn = n-5 * divn;
    }


    if(divn<0) ans=-1;
    else ans = divn+modn/2;

    cout << ans;

    return 0;
}
