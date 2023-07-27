#include <iostream>
#include <cstring>
#define MAX 21
using namespace std;

int store[MAX][MAX][MAX];

int w(int a, int b, int c){
    if(a > 0 && b > 0 && c > 0 &&
       a < MAX && b < MAX && c < MAX &&
       store[a][b][c] != -1)
        return store[a][b][c];

    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    else if(a > 20 || b > 20 || c > 20){
        return w(20, 20, 20);
    }
    else if(a < b && b < c){
        store[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return store[a][b][c];
    }
    else{
        store[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        return store[a][b][c];
    }
}

int main(){
    memset(store, -1, sizeof(store));
    while(true){
        int a, b, c; cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        int result =  w(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << "\n";
    }
}
