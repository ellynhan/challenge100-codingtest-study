#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;

    long long a=1, b=2, c;

    for(int i=3; i<=num; i++){
        c = (a + b) % 15746;
        a = b;
        b = c;
    }
    
    if(num == 1) cout << a;
    else if(num == 2) cout << b;
    else cout << c;
}
