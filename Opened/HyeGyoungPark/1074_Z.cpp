#include <iostream>
#include <cmath>

using namespace std;


int main(void){
    int n,r,c,x,y;
    int ans=0;

    cin >> n >> r >> c;

    x = pow(2,n-1);
    y = pow(2,n-1);


    for(int i=1; n-i>=0 ;i++){

        if(x <= r && y <= c) {
            ans += pow(2,n-i)*pow(2,n-i)*3;
            x += pow(2,n-i-1);
            y += pow(2,n-i-1);
        }

        else if(x <= r && y > c) {
            ans += pow(2,n-i)*pow(2,n-i)*2;
            x += pow(2,n-i-1);
            y -= pow(2,n-i-1);
        }

        else if(x > r && y <= c) {
            ans += pow(2,n-i)*pow(2,n-i);
            x -= pow(2,n-i-1);
            y += pow(2,n-i-1);
        }

        else if(x > r && y > c) {
            ans += 0;
            x -= pow(2,n-i-1);
            y -= pow(2,n-i-1);
        }

    }

    cout << ans;

    return 0;
}
