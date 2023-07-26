#include <iostream>
using namespace std;

int N;
long long answer = -1;
long long combArr[12][12] = {0, };

void init(){
    cin >> N; N++;
}

long long comb(int n, int r){
    if(n-r < r) r = n-r;

    if(combArr[n][r] != 0) return combArr[n][r];

    if(n == r || r == 0) 
        return 1;
    else {
        combArr[n][r] = comb(n-1, r-1) + comb(n-1, r);
        return combArr[n][r];
    } 
}

void findDecreaseNumber(){
    long long num = 0, idx=1, i=0;
    // 2-1. 몇 자리 수인지 찾기.
    while(num < N){
        if(idx == 11) return;
        num += comb(10, idx);
        idx++;
    } idx--;
    // 2-2. 수 찾기 반복
    answer = 0;
    num -= comb(10, idx);
    while(idx != 0){
        i = idx-1;
        while(num < N){
            num += comb(i, idx-1);
            i++;
        } i--;
        answer = answer * 10 + i;
        num -= comb(i, idx-1);
        idx--;
    }
}

void printAnswer(){
    cout << answer;
}

int main(){
    init(); // 1. 입력받기
    findDecreaseNumber(); // 2. 감소하는 수 찾기
    printAnswer(); // 3. 출력하기
}
