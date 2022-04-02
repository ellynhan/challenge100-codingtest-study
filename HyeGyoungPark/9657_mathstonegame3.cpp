#include <iostream>

using namespace std;

int main(void){
    int n;
    
    cin >> n;
    
    if(n%7 == 2 || n%7 == 0)    cout << "CY";
    else cout << "SK";

    return 0;

} 
