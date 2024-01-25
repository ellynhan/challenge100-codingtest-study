//
//  LOAN.cpp
//  main
//
//  Created by wi_seong on 1/17/24.
//

/*
 [Input]
 4
 20000000 12 6.8
 35000000 120 1.1
 40000000 36 0.5
 100 120 0.1
 [Output]
 1728691.4686372071
 308135.8967737053
 1119696.7387703573
 0.8375416659
 */
// 시간복잡도: O(100 * logn)
// 최악시간: 900
// 난이도: 하
// Timer: 15m
// Url: https://algospot.com/judge/problem/read/LOAN

#include <iostream>

using namespace std;
int t, m;
double n, p;

double balance(double amount, int duration, double rates, double monthlyPayment) {
    double balance = amount;

    for(int i = 0; i < duration; i++) {
        balance *= (1.0 + (rates / 12.0) / 100.0);
        balance -= monthlyPayment;
    }

    return balance;
}

double payment(double amount, int duration, double rates) {
    double lo = 0, hi = amount * (1.0 + (rates / 12.0) / 100.0);

    for(int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2.0;
        if(balance(amount, duration, rates, mid) <= 0)
            hi = mid;
        else
            lo = mid;
    }

    return hi;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while(t--) {
        cin >> n >> m >> p;
        cout << payment(n, m, p) << "\n";
    }

	return 0;
}
