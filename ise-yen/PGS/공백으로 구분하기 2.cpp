#include <string>
#include <vector>

using namespace std;

vector<string> solution(string str) {
    vector<string> answer;
    string tmp;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            if(tmp != ""){
                answer.push_back(tmp);
                tmp = "";
            }
        }
        else{
            tmp.push_back(str[i]);
        }
    }
    
    if(tmp != ""){
        answer.push_back(tmp);
    }
    return answer;
}
