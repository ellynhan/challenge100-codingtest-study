#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <numeric>
using namespace std;

bool isPrime(int n) {
    if (n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    vector<bool> result(b - a + 1, true);

    for (int i = a; i <= b; i++) {
        if (!result[i - a])
            continue;
        if (isPrime(i)) {
            printf("%d\n", i);
        }
        else if(i != 1){
            int multiply = i;
            while (multiply <= b) {
                result[multiply - a] = false;
                multiply += i;
            }
        }
    }

    return 0;
}