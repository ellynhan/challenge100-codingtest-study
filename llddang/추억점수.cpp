#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    int idx, semiAnswer;
    for(auto vec : photo){
        semiAnswer = 0;
        for(auto str : vec){
            for(idx = 0; idx < name.size(); idx++){
                if(name[idx] == str){
                    semiAnswer += yearning[idx];
                    break;
                }
            }
        }
        answer.push_back(semiAnswer);
    }
    
    return answer;
}
