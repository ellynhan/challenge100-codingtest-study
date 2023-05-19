//
//  20437.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 2
 superaquatornado
 2
 abcdefghijklmnopqrstuvwxyz
 5
 [Output]
 4 8
 -1
 */
// 시간복잡도: O(n)
// 최악시간: 26,000,000
// 난이도: Gold 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/20437

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t, k;
int mnLen = 10001, mxLen;
string w;
vector<int> vecList[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        mnLen = 10001;
        mxLen = 0;
        cin >> w >> k;
        for(int i = 0; i < 26; i++) vecList[i].clear();
        for(int i = 0; i < w.size(); i++) {
            int num = w[i] - 'a';
            vecList[num].push_back(i);
        }
       
        for(int i = 0; i<26; i++){
            int vsize = (int)vecList[i].size();
            if(vsize >= k){
                for(int j = 0; j <= vsize - k; j++){
                    mnLen = min(mnLen, vecList[i][j + k - 1] - vecList[i][j] + 1);
                    mxLen = max(mxLen, vecList[i][j + k - 1] - vecList[i][j] + 1);
                }
            }
        }
        
        if(mxLen == 0) cout << -1 << '\n';
        else cout << mnLen << ' ' << mxLen <<'\n';
    }
    
    return 0;
}
