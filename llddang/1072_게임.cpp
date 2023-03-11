#include <iostream>
using namespace std;

int main(){
    long long x, y, z;
    cin >> x >> y;
    
    z = y * 100 / x;
    
    if(x == y || z == 99){
        cout << -1;
        return 0;
    }
    
    long long result = ((z + 1) * x - y * 100) / (100 - z -1);
    result += ((z + 1) * x - y * 100) % (100 - z -1) == 0 ? 0 : 1;
    cout << result;
    
    return 0;
}
