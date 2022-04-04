#include <iostream>

using namespace std;

int main(void){
    int n;

    cin >> n;

    if(n%7 == 1 || n%7 == 3)    cout << "CY";
    else cout << "SK";

    return 0;

}
