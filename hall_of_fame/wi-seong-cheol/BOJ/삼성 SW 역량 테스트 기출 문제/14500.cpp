//
//  14500.cpp
//  main
//
//  Created by wi_seong on 3/4/24.
//

/*
 [Input]
 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 [Output]
 20
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 65,536
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/14500

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Point {
    int x, y;
};
int answer;
int n, m;
int board[501][501];

bool isadj(const Point& a, const Point& b) {
    if(a.x == b.x) return abs(a.y - b.y) == 1;
    if(a.y == b.y) return abs(a.x - b.x) == 1;
    return false;
}

bool isConnect(vector<Point>& p) {
    bool flag = false;
    for(int i = 0; i < 4; i++) {
        int cnt = 0;
        for(int j = 0; j < 4; j++) {
            if(isadj(p[i], p[j]))
                cnt++;
        }
        if(cnt == 0) return false;
        if(cnt >= 2) flag = true;
    }
    return flag;
}

void calc(vector<Point>& p) {
    for(int i = 0; i <= n - 4; i++) {
        for(int j = 0; j <= m - 4; j++) {
            int sum = 0;
            for(auto element: p)
                sum += board[i + element.x][j + element.y];
            answer = max(answer, sum);
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    vector<int> brute(16, 0);
    fill(brute.begin() + 12, brute.end(), 1);
    do {
        vector<Point> p;
        for(int i = 0; i < 16; i++)
            if(brute[i]) p.push_back({i / 4, i % 4});
        if(isConnect(p)) calc(p);
    } while(next_permutation(brute.begin(), brute.end()));

    cout << answer;

	return 0;
}
