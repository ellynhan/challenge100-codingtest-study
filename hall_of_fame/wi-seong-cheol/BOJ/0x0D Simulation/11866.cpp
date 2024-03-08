//
//  11866.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 7 3
 [Output]
 <3, 6, 2, 7, 5, 1, 4>
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Silver 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/11866

#include <iostream>
#include <list>
#include <vector>

using namespace std;
int n, k;
list<int> L;
vector<int> v;

void print() {
    cout << "<";
    cout << v.front();
    for(int i = 1; i < int(v.size()); i++) {
        cout << ", " << v[i];
    }
    cout << ">";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++) L.push_back(i);
    auto it = L.begin();

    while(n--) {
        for(int j = 0; j < k - 1; j++) {
            it++;
            if(it == L.end()) it = L.begin();
        }
        v.push_back(*it);
        auto tmp = it++;
        if(it == L.end()) it = L.begin();
        L.erase(tmp);
    }
    print();

	return 0;
}
