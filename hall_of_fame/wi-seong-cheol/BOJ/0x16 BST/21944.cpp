//
//  21944.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 1000 1 1
 1001 2 1
 19998 78 2
 2667 37 3
 2042 55 3
 12
 add 1402 59 1
 recommend 1 1
 recommend2 1
 recommend3 1 50
 recommend3 -1 50
 solved 1000
 solved 2667
 recommend 2 1
 recommend 1 -1
 recommend2 -1
 solved 1001
 recommend 1 -1
 [Output]
 1402
 19998
 2042
 2667
 19998
 1001
 1001
 1402
 */
// 시간복잡도: O(nlogn)
// 최악시간: 50,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/21944

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
string op;
int N, L, P, G, x;
pair<int, int> probLevel[100'002];  // 문제의 (난이도, 분류) 저장
set<int> probByL[102];              // 난이도별로 문제 저장
set<int> probByGL[102][102];        // (분류, 난이도) 별로 문제 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    while(N--) {
        cin >> P >> L >> G;
        probLevel[P] = {L, G};
        probByL[L].insert(P);
        probByGL[G][L].insert(P);
    }
    cin >> N;
    while(N--) {
        cin >> op;
        if(op == "recommend") {
            cin >> G >> x;
            if(x == 1) {
                for(int i = 100; i >= 0; i--) {
                    if(probByGL[G][i].empty()) continue;
                    cout << *(prev(probByGL[G][i].end())) << '\n';
                    break;
                }
            } else {
                for(int i = 0; i <= 100; i++) {
                    if(probByGL[G][i].empty()) continue;
                    cout << *probByGL[G][i].begin() << '\n';
                    break;
                }
            }
        } else if(op == "recommend2") {
            cin >> x;
            if(x == 1) {
                for(int i = 100; i >= 0; i--) {
                    if(probByL[i].empty()) continue;
                    cout << *(prev(probByL[i].end())) << '\n';
                    break;
                }
            } else {
                for(int i = 0; i <= 100; i++) {
                    if(probByL[i].empty()) continue;
                    cout << *probByL[i].begin() << '\n';
                    break;
                }
            }
        } else if(op == "recommend3") {
            cin >> x >> L;
            int problem = -1;
            if(x == 1) {
                for(int i = L; i <= 100; i++){
                    if(probByL[i].empty()) continue;
                    problem = *probByL[i].begin();
                    break;
                }
            } else {
                for(int i = L - 1; i >= 0; i--){
                    if(probByL[i].empty()) continue;
                    problem = *(prev(probByL[i].end()));
                    break;
                }
            }
            cout << problem << '\n';
        } else if(op == "add") {
            cin >> P >> L >> G;
            probLevel[P] = {L, G};
            probByL[L].insert(P);
            probByGL[G][L].insert(P);
        } else {
            cin >> P;
            tie(L, G) = probLevel[P];
            probByL[L].erase(P);
            probByGL[G][L].erase(P);
        }
    }
    
    return 0;
}
/*
 
 1402
 19998
 2042
 2667
 19998
 1001
 1001
 1402
 
 1402
 19998
 2042
 2667
 19998
 1402
 1000
 1402
 */

