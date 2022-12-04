#include <iostream>

using namespace std;
int A, B, C, result=1;

void iterativePow()
{
    while(B != 0){
        if(B&1) result = result * A % C;
        A = A*A%C;
        B >>= 1; 
    }
}

int main()
{
    cin >> A >> B >> C;
    iterativePow();
    cout << result;
}