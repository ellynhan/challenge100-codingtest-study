//
//  3908.cpp
//  main
//
//  Created by wi_seong on 1/10/24.
//

/*
 [Input]
 12
 24 3
 24 2
 2 1
 1 1
 4 2
 18 3
 17 1
 17 3
 17 4
 100 5
 1000 10
 1120 14
 [Output]
 2
 3
 1
 0
 0
 2
 1
 0
 1
 55
 200102899
 2079324314
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 2,637,600
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/3908

#include <iostream>
#include <vector>

using namespace std;
#define SIZE 1120
#define ll long long
int t;
int n, k;
ll d[15][1121];
vector<int> prime;

void sieve() {
    vector<bool> isPrime(SIZE + 1, true);
    for(int i = 2; i < SIZE; i++) {
        if(!isPrime[i]) continue;
        prime.push_back(i);
        for(int j = i * i; j <= SIZE; j += i) {
            isPrime[j] = false;
        }
    }
}

void init_dp() {
    d[0][0] = 1;
    for(int i = 0; i < prime.size(); i++) {
        for(int j = SIZE; j >= prime[i]; j--) {
            for(int k = 1; k <= 14; k++) {
                d[k][j] += d[k - 1][j - prime[i]];
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    sieve();
    init_dp();

    cin >> t;
    while(t--) {
        cin >> n >> k;
        cout << d[k][n] << '\n';
    }

	return 0;
}
