#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    int T; cin >> T;
    string exe, input;
    int len;
    vector<string> answer;
    while(T--){
        cin >> exe >> len >> input;
        
        int Dcnt = 0;
        for(int i=0; i<exe.size(); i++){
            if(exe[i] == 'D') Dcnt++;
        }
        if(Dcnt > len){
            answer.push_back("error");
            continue;
        } else if(Dcnt == len){
            answer.push_back("[]");
            continue;
        }

        vector<int> arr; string tmp;
        for(int i=1; i<input.size(); i++){
            if(input[i] == ',' || input[i] == ']'){
                arr.push_back(stoi(tmp));
                tmp = "";
            } else tmp += input[i];
        }

        bool reverseFlag = false;
        int s = 0, e = arr.size();
        for(int i=0; i<exe.size(); i++){
            if(exe[i] == 'R') reverseFlag = !reverseFlag;
            if(exe[i] == 'D'){
                if(!reverseFlag) s++;
                else e--;
            }
        }
        vector<int> newArr(arr.begin() + s, arr.begin() + e);
        if(reverseFlag) reverse(newArr.begin(), newArr.end());

        string ret = "[";
        for(int a:newArr) ret += to_string(a) + ",";
        ret[ret.size()-1] = ']';

        answer.push_back(ret);
    }
    
    for(string an : answer) cout << an << "\n";
}
