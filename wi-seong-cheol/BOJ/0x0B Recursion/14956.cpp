//
//  14956.cpp
//  main
//
//  Created by wi_seong on 2022/11/21.
//

/*
 [Input]
 4 10
 [Output]
 3 4
 */
// 시간복잡도: O(logN)
// 최악시간: 9
// 난이도: Gold 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14956

#include <iostream>

using namespace std;
#define X first
#define Y second

pair<int, int> philo(int side, int walk) {
    if(side == 2) {
        switch (walk) {
            case 1:
                return {1, 1};
            case 2:
                return {1, 2};
            case 3:
                return {2, 2};
            case 4:
                return {2, 1};
        }
    }
    int half = side / 2, section = half * half;
    
    if(walk <= section) {
        pair<int, int> rv = philo(half, walk);
        return {rv.Y, rv.X};
    } else if(walk <= 2 * section) {
        pair<int, int> rv = philo(half, walk - section);
        return {rv.X, half + rv.Y};
    } else if(walk <= 3 * section) {
        pair<int, int> rv = philo(half, walk - 2 * section);
        return {half + rv.X, half + rv.Y};
    } else {
        pair<int, int> rv = philo(half, walk - 3 * section);
        return {2 * half - rv.Y + 1, half - rv.X + 1};
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int side, walk; cin >> side >> walk;
    pair<int, int> ans = philo(side, walk);
    cout << ans.X << ' ' << ans.Y;
    
    return 0;
}
