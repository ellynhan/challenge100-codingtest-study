//
//  MORSE.cpp
//  main
//
//  Created by wi_seong on 1/15/24.
//

/*
 [Input]
 3
 2 2 4
 4 8 13
 6 4 1
 [Output]
 o--o
 --o-ooo-oooo
 ------oooo
 */
// 시간복잡도: O()
// 최악시간: 
// 난이도: 중
// Timer: 30분
// Url: https://algospot.com/judge/problem/read/MORSE

#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1000000000 + 100;
int t, n, m, k;
int bino[201][201];

void calcBino() {
    for(int i = 0; i <= 200; i++) {
        bino[i][0] = bino[i][i] = 1;
        for(int j = 1; j < i; j++) {
            bino[i][j] = min(MAX, bino[i - 1][j - 1] + bino[i - 1][j]);
        }
    }
}

string kth(int n, int m, int skip) {
    if(n == 0) return string(m, 'o');
    if(skip < bino[n + m - 1][n - 1]) {
        return "-" + kth(n - 1, m, skip);
    }
    return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    calcBino();

    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        k--;
        cout << kth(n, m, k) << endl;
    }

	return 0;
}
