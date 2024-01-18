#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> um;
    for(int i = 0; i < participant.size(); i++){
        auto it = um.find(participant[i]);
        if(it == um.end()){
            um.insert({participant[i], 1});
        }
        else{
            um[participant[i]]++;
        }
    }
    
    for(int i = 0; i < completion.size(); i++){
        auto it = um.find(completion[i]);
        if(it != um.end()){
            um[completion[i]]--;
        }
    }
    
    for(auto it : um){
        if(it.second != 0){
            answer = it.first;
        }
    }
    
    return answer;
}
