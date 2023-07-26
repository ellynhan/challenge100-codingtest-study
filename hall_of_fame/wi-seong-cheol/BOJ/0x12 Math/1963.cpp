//
//  1963.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 3
 1033 8179
 1373 8017
 1033 1033
 [Output]
 6
 7
 0
 */
// 시간복잡도: O(n^2)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1963

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
#define SIZE 10000
int t, a, b;
int dist[SIZE];
vector<string> prime;
vector<bool> isPrime(SIZE, true);

void sieve() {
    isPrime[1] = false;
    for(int i = 2; i < SIZE; i++) {
        if(!isPrime[i]) continue;
        if(i > 1000)
            prime.push_back(to_string(i));
        for(int j = i * i; j < SIZE; j += i)
            isPrime[j] = false;
    }
}

int sameCount(const string& s1, const string& s2) {
    int cnt = 0;
    for(int i = 0; i < 4; i++)
        if(s1[i] == s2[i]) cnt++;
    return cnt;
}

int bfs() {
    fill(dist, dist + SIZE, -1);
    queue<string> Q;
    Q.push(to_string(a));
    dist[a] = 0;
    
    while(!Q.empty()) {
        string cur = Q.front(); Q.pop();
        if(cur == to_string(b)) return dist[b];
        for(string nxt: prime) {
            int cnt = sameCount(cur, nxt);
            if(cnt != 3 || dist[stoi(nxt)] != -1) continue;
            dist[stoi(nxt)] = dist[stoi(cur)] + 1;
            Q.push(nxt);
        }
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    sieve();
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << bfs() << '\n';
    }
    
    return 0;
}
