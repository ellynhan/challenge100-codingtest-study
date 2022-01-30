#include <bits/stdc++.h>

using namespace std;

vector<string> patern;
vector<bool> result;
string sound;
bool answer;

void input() {
    int testCase;
    cin >> testCase;
    while(testCase--) {
        cin >> sound;
        patern.push_back(sound);
    }
}


int first(int j) {
    if(j >= sound.size()) { answer=false; return j; }
    else if(sound[j] == '0' && sound[j+1] == '0') {                    // 00
        j+= 2;
        while(j < sound.size()) {                                      //0반복
            if(sound[j] != '0') break;
            j+=1;
        }
        if(j >= sound.size()) { answer=false; return sound.size(); }   //1
        while(j < sound.size()) {                                      //1반복
            if(sound[j] != '1') break;
            j+=1;
        }
        return j;
    }
    else { answer=false; return sound.size(); }
}


int second(int j) {
    if(j >= sound.size()) { answer=false; return j; }
    else if(sound[j] == '1') { return j+1; }
    else {
        //10011001인 경우에는 second가 아닌 first로 인식
        if(j>3 && sound[j-3]=='1' && sound[j-2]=='1') return first(j-1);
        else  { answer=false; return sound.size(); }
    }
}


void solve() {
    for(auto p : patern) {
        sound = p;
        int i=0; answer = true;
        while(i < sound.size()) {
            if(sound[i] == '1') i = first(i+1);          //100+1+인지 판단
            else if(sound[i] == '0') i = second(i+1);    //01인지 판단
        }
        if(sound.size()==0) answer=false;
        result.push_back(answer);
    }
}


void output() {
    for(auto r : result) {
        if(r==true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}


int main() {
    input();
    solve();
    output();
    return 0;
}
