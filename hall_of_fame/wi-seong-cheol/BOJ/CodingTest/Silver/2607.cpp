//
//  2607.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 4
 DOG
 GOD
 GOOD
 DOLL
 [Output]
 2
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: Silver 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2607

#include <iostream>
#include <algorithm>

using namespace std;
int n, ans;
int len1, len2;
string first, comp;
int firstChk[26], ccopy[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> first;
    len1 = (int)first.size();
    for(char ch: first)
        firstChk[ch - 'A']++;
    for(int i = 0; i < n - 1; i++) {
        copy(firstChk, firstChk + 26, ccopy);
        cin >> comp;
        len2 = (int)comp.size();
        int same = 0;
        for(char ch: comp)
            if(ccopy[ch - 'A'] > 0) {
                ccopy[ch - 'A']--;
                same++;
            }
        if(len1 == len2) { //두개의 길이가 같을 때
            if(same == len1 || same == len1 - 1) {
                //구성이 아예 같거나, 한글자가 다른경우
                ans++;
            }
        }
        //기준 문자열이 한 글자 길 때 => 한 글자가 추가
        else if(len1 - 1 == len2 && same == len1 - 1)
            ans++;
        
        //기준 문자열이 한 글자 짧을 때 => 한 글자 삭제
        else if(len1 + 1 == len2 && same == len1)
            ans++;
    }
    cout << ans;
    
    return 0;
}
