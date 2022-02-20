#include <iostream>

using namespace std;

int main(void){
    int n,ans=0;

    cin >> n;

    for(int i=1; i<=n; i++){
        if(i*i<=n){ans++;}

        else break;
    }

    cout << ans;

    return 0;

}
