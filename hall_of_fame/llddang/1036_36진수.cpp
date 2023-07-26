#include <algorithm>
#include <iostream>

using namespace std;

struct THIRTYSIX{ int num, pos[52]={0, };};
THIRTYSIX arr[36];
THIRTYSIX change[36];
int answer[52];
int sortIdx[36];
int N, k;

void init(){
    cin >> N;
    string input;
    for(int i=0; i<36; i++) arr[i].num = i, change[i].num = i, sortIdx[i]=i;
    for(int i=0; i<N; i++){
        cin >> input;
        for(int j=0; j<input.size(); j++){
            int idx = input[j] < 'A' ? input[j] - '0' : input[j] - 'A' + 10;
            arr[idx].pos[input.size() - 1 - j]++;
        }
    }
    cin >> k;
}

void calc(){
    for(int i=0; i<36; i++){
        int c = 0;
        for(int j=0; j<52; j++){
            int tmp = arr[i].pos[j] * (35 - arr[i].num) + c;
            change[i].pos[j] = tmp % 36;
            c = tmp / 36;
        }
    }
}

bool comp(int a, int b){
    for(int i=51; i>=0; i--){
        if(change[a].pos[i] == change[b].pos[i]) continue;
        return change[a].pos[i] > change[b].pos[i];
    }
    return false;
}

void changeToZ(){
    for(int i=0; i<k; i++){
        arr[sortIdx[i]].num = 35;
    }
}

void add(){
    int c = 0;
    for(int i=0; i<52; i++){
        int sum = c;
        for(int j=0; j<36; j++){
            sum += arr[j].num * arr[j].pos[i];
        }
        answer[i] = sum % 36;
        c = sum / 36;
    }
}

void print(){
    string out = ""; int i;
    for(i=51; i>=0; i--){
        out += answer[i] < 10 ? answer[i] + '0' : answer[i] - 10 + 'A';
    }
    for(i=0; out[i] == '0'; i++);
    if(i == out.size()) cout << "0";
    else cout << out.substr(i);
}

int main(){
    // 1. 숫자가 몇번째에 있는지 자리를 기반으로 입력 받기
    init();
    // 2. 숫자가 Z로 변경되었을 때의 변화를 측정
    calc();
    // 3. (2)의 측정을 기준으로 정렬하기
    sort(sortIdx, sortIdx+36, comp);
    // 4. 상위 k개의 숫자를 Z로 변경
    changeToZ();
    // 5. 숫자들 더하기!
    add();
    // 6. 출력
    print();
    return 0;
}
