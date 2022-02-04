#include<bits/stdc++.h>
#define BIG(a,b) ((a)>(b))?(a):(b)
#define SMALL(a,b) ((a)>(b))?(b):(a)

using namespace std;

float distance(int x1, int y1, int x2, int y2) {
    int doubleDist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return sqrt(doubleDist);
}

void output(float dist, int diff, int sum) {
    if(dist == 0 && diff == 0) cout << -1 << endl;
    else if (diff < dist && dist < sum) cout << 2 << endl;
    else if (dist == diff) cout << 1 << endl;
    else if (dist == sum) cout << 1 << endl;
    else cout << 0 << endl;

}

void data() {
    int x1,y1,r1;
    int x2,y2,r2;
    int testCase, diff, sum;
    float dist;
    cin >> testCase;
    while(testCase--) {
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;
        dist = distance(x1, y1, x2, y2);
        diff = (BIG(r1, r2)) - (SMALL(r1, r2));
        sum = r1 + r2;
        output(dist, diff, sum);
    }
}

int main() {
    data();
    return 0;
}
