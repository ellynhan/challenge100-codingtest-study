// 팩토리얼 / 브론즈 3
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}

int main() {
    int N;
    cin >> N;
    cout << factorial(N);
    return 0;
}