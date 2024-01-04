//
//  PICNIC.cpp
//  main
//
//  Created by wi_seong on 1/4/24.
//

/*
 [Input]
 3
 2 1
 0 1
 4 6
 0 1 1 2 2 3 3 0 0 2 1 3
 6 10
 0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
 [Output]
 1
 3
 4
 */
// 시간복잡도: O(2 ^ n)
// 최악시간: 945
// 난이도: 하
// Timer: 15m
// Url: https://www.algospot.com/judge/problem/read/PICNIC

#include <iostream>
#include <cstring>

using namespace std;
int t, n, m;
bool isFriend[10][10];

int countPairing(bool taken[10]) {
    int firstFree = -1;
    for(int i = 0; i < n; i++) {
        if(!taken[i]) {
            firstFree = i;
            break;
        }
    }
    if(firstFree == -1) return 1;

    int ret = 0;
    for(int pairWith = firstFree + 1; pairWith < n; pairWith++) {
        if(!taken[pairWith] && isFriend[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairing(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < 10; i++)
            memset(isFriend[i], false, sizeof(isFriend[i]));
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            isFriend[a][b] = isFriend[b][a] = true;
        }
        bool taken[10] = {false, };
        cout << countPairing(taken) << "\n";
    }

	return 0;
}
