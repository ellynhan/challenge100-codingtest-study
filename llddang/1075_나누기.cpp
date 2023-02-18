#include <iostream>
using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;
    
    long long c = a / 100 * 100;
    
    int rest = c % b;
    
    if(rest == 0)
        cout << "00";
    else if(b - rest < 10)
        cout << "0" << b - rest;
    else
        cout << b - rest;
    
    return 0;
}
