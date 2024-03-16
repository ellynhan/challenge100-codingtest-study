//
//  20055.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 12/29/23.
//

/*
 [Input]
 3 2
 1 2 1 2 1 2
 [Output]
 2
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 40,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/20055

#include <iostream>
#include <algorithm>

using namespace std;
int n, k, t;
int belt[201], robot[201];

// 컨베이어 벨트 이동
void rotate_belt() {
    int belt_tmp = belt[2 * n];
    for(int i = 2 * n - 1; i >= 1; i--) {
        swap(robot[i + 1], robot[i]);
        swap(belt[i + 1], belt[i]);
    }
    belt[1] = belt_tmp;

    // 로봇 하차
    if(robot[n] == 1)
        robot[n]--;
}

// 로봇 이동
void move_robot() {
    for(int i = n - 1; i >= 1; i--) {
        if(robot[i] == 0) continue;
        if(robot[i + 1] == 0 && belt[i + 1] != 0) {
            belt[i + 1]--;
            swap(robot[i + 1], robot[i]);
        }
    }

    // 로봇 하차
    if(robot[n] == 1)
        robot[n]--;
}

// 물건을 올려놓음
void put() {
    if(robot[1] == 0 && belt[1] != 0) {
        belt[1]--;
        robot[1] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= 2 * n; i++)
        cin >> belt[i];

    while(1) {
        t++;

        // 컨베이어 벨트 이동
        rotate_belt();
        // 로봇 이동
        move_robot();
        // 물건을 올려놓음
        put();

        // 내구도가 0인 블럭의 개수가 K개 이상이라면 컨베이어 벨트가 폐쇄
        int cnt = 0;
        for(int i = 1; i <= 2 * n; i++)
            cnt += (belt[i] == 0);
        if(cnt >= k) break;
    }
    cout << t;

    return 0;
}
