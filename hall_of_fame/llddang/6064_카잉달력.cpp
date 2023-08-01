#include <iostream>
using namespace std;

int lcd(int a, int b){
    int minv = min(a, b);
    int maxv = max(a, b);

    int c;
    while(minv != 0){
        c = maxv % minv;
        maxv = minv;
        minv = c;
    }
    return maxv;
}

int gcd(int a, int b){
    return a * b / lcd(a, b);
}

int main(){
    int T; cin >> T;
    while(T--){
        int M, N; cin >> M >> N;
        int x, y; cin >> x >> y;
        int g = gcd(M, N);
        x %= M; y %= N;
        while(x <= g && x % N != y){
            x += M;
        }

        if(x == 0 && y == 0) cout << g << "\n";
        else if(x <= g) cout << x << "\n";
        else cout << "-1\n";
    }
}
