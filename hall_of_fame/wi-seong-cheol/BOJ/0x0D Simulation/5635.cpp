//
//  5635.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/6/24.
//

/*
 [Input]
 5
 Mickey 1 10 1991
 Alice 30 12 1990
 Tom 15 8 1993
 Jerry 18 9 1990
 Garfield 20 9 1990
 [Output]
 Tom
 Jerry
 */
// 시간복잡도: O(nlogn)
// 최악시간: 200
// 난이도: Silver 5
// Timer: 2m
// Url: https://www.acmicpc.net/problem/5635

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Person {
    string name;
    int d, m, y;
};
int n;
vector<Person> v;

bool cmp(Person a, Person b) {
    if(a.y == b.y) {
        if(a.m == b.m) {
            return a.d < b.d;
        }
        return a.m < b.m;
    }
    return a.y < b.y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        string name;
        int d, m, y;
        cin >> name >> d >> m >> y;
        v.push_back({name, d, m, y});
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[n-1].name << '\n' << v[0].name;

	return 0;
}
