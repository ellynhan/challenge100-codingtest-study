#include <bits/stdc++.h>

using namespace std;

int needed, N;
int priceSix, priceOne;
int minSix=1000, minOne=1000, minPrice;

void input() {
    cin >> needed;
    cin >> N;
    while(N--) {
        cin >> priceSix;
        cin >> priceOne;
        if(priceSix < minSix) minSix=priceSix;
        if(priceOne < minOne) minOne=priceOne;
    }
}


void output() {
    int setN = needed/6;
    if(minOne*6 < minSix) minPrice = minOne*needed;
    else { minPrice = min((setN+1)*minSix, setN*minSix+(needed-setN*6)*minOne); }
    cout << minPrice << endl;
}

int main() {
    input();
    output();
    return 0;
}
