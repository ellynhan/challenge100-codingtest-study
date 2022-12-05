//
//  10825.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/30.
//

/*
 [Input]
 12
 Junkyu 50 60 100
 Sangkeun 80 60 50
 Sunyoung 80 70 100
 Soong 50 60 90
 Haebin 50 60 100
 Kangsoo 60 80 100
 Donghyuk 80 60 100
 Sei 70 70 70
 Wonseob 70 70 90
 Sanghyun 70 70 80
 nsj 80 80 80
 Taewhan 50 60 90
 [Output]
 Donghyuk
 Sangkeun
 Sunyoung
 nsj
 Wonseob
 Sanghyun
 Sei
 Kangsoo
 Haebin
 Junkyu
 Soong
 Taewhan
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Silver 4
// Timer: 5m
// Url: https://www.acmicpc.net/problem/10825

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
int n;
vector<tuple<int, int, int, string>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--) {
        string name;
        int x, y, z;
        cin >> name >> x >> y >> z;
        v.push_back({-x, y, -z, name});
    }
    sort(v.begin(), v.end());
    for(auto element: v)
        cout << get<3>(element) << '\n';
    
    return 0;
}
