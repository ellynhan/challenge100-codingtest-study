#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> type_map;
    char types[4][2] = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};
         
    for(int i=0; i<survey.size(); i++){
        if(choices[i] < 4){
            type_map[survey[i][0]] += 4 - choices[i];
        } else{
            type_map[survey[i][1]] += choices[i] - 4;
        }
    }
    for(int i=0; i<4; i++){
        answer += type_map[types[i][0]] >= type_map[types[i][1]] ? types[i][0] : types[i][1];
    }
    return answer;
}