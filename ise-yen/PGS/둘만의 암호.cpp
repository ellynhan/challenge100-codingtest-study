#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i = 0; i < s.size(); i++){
        for(int j = 1; j <= index; j++){
            s[i]++;
            if(s[i] > 'z') s[i] = 'a';
            auto it = skip.find(s[i]);
            if(it != string::npos) j--;
        }
        answer.push_back(s[i]);
    }
    return answer;
}
