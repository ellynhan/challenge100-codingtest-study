#include <iostream>

using namespace std;
int Gcd(int a, int b){
    int m;
    while(b != 0){
        m = a % b;
        a = b;
        b = m;
    }

    return a;
}

int Lcm(int a, int b, int m){
    int r;
    r = (a/m) * (b/m) * m;

    return r;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int gcd = Gcd(a, b);
    int lcm = Lcm(a, b, gcd);

    cout << gcd << "\n";
    cout << lcm;

    return 0;
}
