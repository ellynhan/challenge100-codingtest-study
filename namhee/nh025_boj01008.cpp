#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int a = 0, b = 0;
    cin >> a >> b;
    cout << setprecision(9);
    cout << fixed << (double)a/b;
}
