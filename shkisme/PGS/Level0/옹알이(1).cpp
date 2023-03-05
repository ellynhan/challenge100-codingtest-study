#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = babbling.size();
    vector<string> can = {"aya", "ye", "woo", "ma"};

    for (string b : babbling){
        for (string c : can){
            if (b.find(c) != string::npos){ // 찾은 경우
                b.replace(b.find(c), c.length(), ",");
            }
        }

        for (char chr: b){
            if (chr != ','){
                answer--;
                break;
            }
        }
    }

    return answer;
}
