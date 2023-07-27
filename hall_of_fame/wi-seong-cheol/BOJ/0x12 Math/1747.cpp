//
//  1747.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 31
 [Output]
 101
 */
// 시간복잡도: O(nlog(logn))
// 최악시간: 1,000,000
// 난이도: Silver 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1747

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 2000001;
int n;
vector<bool> isPrime(SIZE, true);

void sieve() {
    isPrime[1] = false;
    for(int i = 2; i*i < SIZE; i++) {
        if(!isPrime[i]) continue;
        for(int j = i*i; j < SIZE; j+=i)
            isPrime[j] = false;
    }
}

bool isPalindrome(int n) {
    int tmp = n;
    int rev_n = 0;
    while(tmp) {
        rev_n *= 10;
        rev_n += tmp % 10;
        tmp /= 10;
    }
    return rev_n == n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    sieve();
    for(int i = n; i < SIZE; i++) {
        if(isPrime[i] && isPalindrome(i)) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
