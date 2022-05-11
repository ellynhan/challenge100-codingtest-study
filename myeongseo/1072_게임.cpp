// 1072번 게임 실버3
#include <bits/stdc++.h>

using namespace std;

long long X, Y;
long long x, startx, endx;


void solve() {
    if(100*Y/X >= 99) { cout << -1 << endl; return; }

    startx = 0; endx = 1000000000;
    while(startx <= endx) {
        x = (startx + endx)/2;
        if(100*Y/X < 100*(Y+x)/(X+x)) { endx = x - 1; }
        else startx = x + 1;
    }
    cout << startx << endl;
}


int main() {
    cin >> X >> Y;
    solve();
    return 0;
}
