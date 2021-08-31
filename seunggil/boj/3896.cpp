#include <iostream>
#include <cmath>

using namespace std;

bool checkPrime(int number) {
    int a = static_cast<int>(sqrt(number));
    for (int i = 2; i <= a; i++)
        if (number % i == 0)
            return false;
    return true;
}

int main(void) {
    int n;

    cin >> n;

    while (n--) {
        int number;
        cin >> number;
        
        if (checkPrime(number))
            cout << 0 << '\n';
        else {
            int result = 1;
            int number2 = number;
            number++;
            number2--;
            while (!checkPrime(number)) {
                number++;
                result++;
            }
            while (!checkPrime(number2)) {
                number2--;
                result++;
            }

            cout << result+1 << '\n';
        }

    }

    return 0;
}