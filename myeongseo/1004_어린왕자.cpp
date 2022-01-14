#include<bits/stdc++.h>

using namespace std;

int output(int x1, int y1, int x, int y, int r) {
    int doubleLen = (x1-x)*(x1-x) + (y1-y)*(y1-y);
    if(doubleLen < r*r) return 1;
    else return 0;
}

void data() {
    int numData, numPlanet, in, through;
    int x1, y1, x2, y2;
    int x, y, r;
    cin >> numData;
    while(numData--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> numPlanet;
        through = 0;
        while(numPlanet--) {
            cin >> x >> y >> r;
            in = 0;
            in += output(x1, y1, x, y, r);
            in += output(x2, y2, x, y, r);
            if(in == 1) through +=1;
        }
        cout <<through <<endl;
    }
}

int main() {
    data();
    return 0;
}
