//
//  2876.cpp
//  main
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 1
 1 5
 [Output]
 1 1
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2876

#include <iostream>
#include <algorithm>

using namespace std;
const int SIZE = 100'001;
int n, a, b, mxLen, g = 6;
int grade[SIZE][2];
int d[SIZE][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> grade[i][0] >> grade[i][1];
    
    d[0][0] = d[0][1] = 1;
    for(int i = 1; i < n; i++) {
        for(int pos = 0; pos < 2; pos++) {
            d[i][pos] = 1;
            if(grade[i][pos] == grade[i - 1][0])
                d[i][pos] = max(d[i][pos], d[i - 1][0] + 1);
            if(grade[i][pos] == grade[i - 1][1])
                d[i][pos] = max(d[i][pos], d[i - 1][1] + 1);
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int pos = 0; pos < 2; pos++) {
            if(d[i][pos] == mxLen)
                g = min(g, grade[i][pos]);
            else if(d[i][pos] > mxLen) {
                mxLen = d[i][pos];
                g = grade[i][pos];
            }
        }
            
    }
    cout << mxLen << ' ' << g;
    
    return 0;
}

