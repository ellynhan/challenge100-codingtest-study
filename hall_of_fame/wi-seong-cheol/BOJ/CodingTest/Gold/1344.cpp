//
//  1344.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/09.
//

/*
 [Input]
 50
 50
 [Output]
 0.5265618908306351
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1344

#include <iostream>

using namespace std;
double ans = 1;
double A, B;
double D[19][19][19]; // D[t][a][b] : t번째에서 A팀이 a점, B팀이 b점
double d[19][19][19];
int arr[] = {0, 1, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> A >> B;
    A /= 100;
    B /= 100;
    D[0][0][0] = 1;
    int T = 18;
    for(int t = 0; t < T; t++) {
        for(int a = 0; a < t + 1; a++) {
            for(int b = 0; b < t + 1; b++) {
                D[t + 1][a][b] += D[t][a][b] * (1 - A) * (1 - B);
                D[t + 1][a + 1][b] += D[t][a][b] * A * (1 - B);
                D[t + 1][a][b + 1] += D[t][a][b] * (1 - A) * B;
                D[t + 1][a + 1][b + 1] += D[t][a][b] * A * B;
            }
        }
    }
    for(auto p: arr)
        for(auto q: arr)
            ans -= D[T][p][q];
    
    cout << fixed;
    cout.precision(20);
    cout << ans;
    
    return 0;
}
