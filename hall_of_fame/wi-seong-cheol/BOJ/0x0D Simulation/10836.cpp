//
//  10836.cpp
//  main
//
//  Created by wi_seong on 1/11/24.
//

/*
 [Input]
 4 2
 2 3 2
 0 6 1
 [Output]
 3 3 4 5
 3 3 4 5
 2 3 4 5
 2 3 4 5
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 490,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/10836

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int board[701][701];

void init() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[i][j] = 1;
}

void sideGrowth(int length) {
    for(int i = n - 1; i >= max(0, n - length); i--) {
        board[0][i]++;
    }
    for(int i = 1; i <= max(0, length - n); i++) {
        board[i][0]++;
    }
}

void growth() {
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            board[i][j] = max(board[i - 1][j], max(board[i][j - 1], board[i - 1][j - 1]));
        }
    }
}

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    init();
    while(m--) {
        int zero, one, two;
        cin >> zero >> one >> two;
        sideGrowth(one + two);
        sideGrowth(two);
    }
    growth();
    print();

	return 0;
}
