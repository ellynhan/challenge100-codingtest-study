#include <iostream>
#include <cmath>
using namespace std;

int fourSquares(int num);

int main(){
    int n; cin >> n;
    cout << fourSquares(n);
}

int fourSquares(int num){
    int x1 = sqrt(num);
    int x2=0, x3=0, x4=0;

    if(x1*x1 == num) return 1;
    x2 = sqrt(num - x1*x1);
    while(x1 > 0){
        if((x1*x1 + x2*x2) == num) return 2;
        else if((x1*x1 + x2*x2) > num){
            x1--;
            x2 = sqrt(num - x1*x1)-1;
        }
        x2++;
    }
  
    x1 = sqrt(num);
    x2 = sqrt(num - x1*x1);
    x3 = sqrt(num - x1*x1 - x2*x2);
    while(x1 > 0){
        if((x1*x1 + x2*x2 + x3*x3) == num) return 3;
        else if((x1*x1 + x2*x2 + x3*x3) > num){
            x2--;
            x3 = sqrt(num - x1*x1 - x2*x2)-1;
        }
        if(x2 < 1){
            x1--;
            x2 = sqrt(num - x1*x1);
            x3 = sqrt(num - x1*x1 - x2*x2)-1;
        }
        x3++;
    }
  
    return 4;
}
