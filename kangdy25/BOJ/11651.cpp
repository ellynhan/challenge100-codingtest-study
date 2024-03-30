#include <bits/stdc++.h>
using namespace std;

struct coord {
    int x;
    int y;
};

bool compare(coord a, coord b) {
    if (a.y == b.y) {
        return a.x < b.x;
    } else {
        return a.y < b.y;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    coord point[100001];
    for (int i = 0; i < N; i++) {
        cin >> point[i].x >> point[i].y;
    }
    
    sort(point, point + N, compare);
    
    for (int i = 0; i < N; i++) {
        cout << point[i].x << " " << point[i].y << "\n";
    }
}