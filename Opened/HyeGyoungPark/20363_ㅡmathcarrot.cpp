#include <iostream>

using namespace std;

int main(void){
    int sun,water,cnt;

    cin >> sun >> water;

    if(sun>water){
        cnt = sun + water + water/10;
    }
    else{
        cnt = sun + water + sun/10;
    }

    cout << cnt;

    return 0;

}
