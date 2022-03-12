#include <bits/stdc++.h>

using namespace std;

int N, divisor;
int minN=1000000, maxN=0;

int main() {
    cin >> N;
    while(N--) {
        cin >> divisor;
        if(divisor < minN) minN=divisor;
        if(divisor > maxN) maxN=divisor;
    }
    cout << minN*maxN << endl;
    return 0;
}
