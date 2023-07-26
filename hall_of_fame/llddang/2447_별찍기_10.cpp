#include <iostream>
#include <cstring>
using namespace std;

void printStar(int x, int y, int n);
char star[2188][2188];

int main(){
    int n; cin >> n;
    memset(star, ' ', sizeof(star));
    printStar(0, 0, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << star[i][j];
        }
        cout << "\n";
    }
}

void printStar(int x, int y, int n){
    if(n == 1) star[x][y] = '*';
    else{
        int div = n/3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i != 1 || j != 1)
                    printStar(x+(i*div), y+(j*div), div);
            }
        }
    }
}
