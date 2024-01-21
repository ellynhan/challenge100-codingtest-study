//
//  ALLERGY.cpp
//  main
//
//  Created by wi_seong on 1/16/24.
//

/*
 [Input]
 2
 4 6
 cl bom dara minzy
 2 dara minzy
 2 cl minzy
 2 cl dara
 1 cl
 2 bom dara
 2 bom minzy
 10 7
 a b c d e f g h i j
 6 a c d h i j
 3 a d i
 7 a c f g h i j
 3 b d g
 5 b c f h i
 4 b e g j
 5 b c g h i
 [Output]
 2
 3
 */
// 시간복잡도: O(2 ^ m)
// 최악시간: 휴리스틱 최적화로 인해 측정불가
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/ALLERGY

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int t, n, m;
vector<int> canEat[50], eaters[50];
int best;

void init() {
    for(int i = 0; i < 50; i++) {
        canEat[i].clear();
        eaters[i].clear();
    }
}

void search(vector<int>& edible, int chosen) {
    if(chosen >= best) return;
    int first = 0;
    while(first < n && edible[first] > 0) first++;
    if(first == n) {
        best = chosen;
        return;
    }
    for(int i = 0; i < canEat[first].size(); i++) {
        int food = canEat[first][i];
        for(int j = 0; j < eaters[food].size(); j++)
            edible[eaters[food][j]]++;
        search(edible, chosen + 1);
        for(int j = 0; j < eaters[food].size(); j++)
            edible[eaters[food][j]]--;
    }
}

int solve() {
    vector<int> edible(n, 0);
    best = m;
    search(edible, 0);
    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        init();
        unordered_map<string, int> names;
        for(int i = 0; i < n; i++) {
            string name; cin >> name;
            names[name] = i;
        }
        for(int food = 0; food < m; food++) {
            int num; cin >> num;
            for(int j = 0; j < num; j++) {
                string name; cin >> name;
                int eater = names[name];
                canEat[eater].push_back(food);
                eaters[food].push_back(eater);
            }
        }
        cout << solve() << '\n';
    }

    return 0;
}
