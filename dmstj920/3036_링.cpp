#include <iostream>

using namespace std;

int Gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int num, i, first, gcd;
    int ring[100];
    cin >> num;
    cin >> first;

    for(i=0; i<num-1; i++){
        cin >> ring[i];
        gcd = Gcd(first, ring[i]);
        cout << first / gcd << "/" << ring[i] / gcd << "\n";
    }


    return 0;
}
