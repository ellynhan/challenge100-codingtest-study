#include <bits/stdc++.h>
using namespace std;

int checkValue[500000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 카드숫자, 개수
    map<int, int> myCard;
    map<int, int>::iterator it;
    pair<map<int, int>::iterator, bool> pr;

    int N, M, cardValue;
    cin >> N;
    // N개의 값을 map 자료형에 저장하고 개수 체크
    for (int i = 0; i < N; i++) {
        cin >> cardValue;
        // insert 함수의 결과값을 pair에 저장 (이터레이터, 불리언)
        pr = myCard.insert(pair<int, int>(cardValue, 1));
        // insert 함수의 결과값(불리언)이 false(중복이면) myCard 값 1개 증가
        if (!pr.second)
            myCard[cardValue]++;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> checkValue[i];
        cout << myCard[checkValue[i]] << " ";
    }
}