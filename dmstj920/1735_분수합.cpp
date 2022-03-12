#include <iostream>

using namespace std;

int Gcd(int a, int b){
    int r;
    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int fraction[2][2];
    int numerator, denominator, gcd, i;

    for(i=0; i<2; i++){
        cin >> fraction[i][0] >> fraction[i][1];
    }

    denominator = fraction[0][1] * fraction[1][1];
    numerator = fraction[0][0] * fraction[1][1] + fraction[1][0] * fraction[0][1];

    gcd = Gcd(numerator, denominator);

    cout << numerator / gcd << " " << denominator / gcd;

    return 0;
}
