#include <string>
#include <vector>
#include <iostream>
#define DIFF_UPPER_LOWER 32

using namespace std;

string toLowerCaseAndFilter(string str){
    string temp = "";
    for(int i=0; i<str.length(); i++){
        if( str[i] >= 'A' && str[i] <= 'Z')
            str[i] += DIFF_UPPER_LOWER;
        
        if((str[i] >= 'a' && str[i] <= 'z') || isdigit(str[i]) || 
              str[i] == '-' || str[i] == '_' || str[i] == '.')
            temp += str[i];
    }
    return temp;
}
string getRemovedConsecutiveDots(string str){
    string temp = "";
    temp += str[0];
    for(int i=1; i<str.length(); i++){
        if(str[i - 1] == '.' && str[i] == '.'){
            continue;
        }
        temp += str[i];
    }
    return temp;
}
string removeBothEndpoints(string str){
    string temp = "";
    for(int i = 0; i<str.length(); i++){
        if((i == 0 && str[i] == '.') || ((i == str.length() - 1 && str[i] == '.')))
            continue;
        temp += str[i];
    }
    return temp;
}

string solution(string new_id) {
    string answer = "";
    answer = toLowerCaseAndFilter(new_id);
    answer = getRemovedConsecutiveDots(answer);
    answer = removeBothEndpoints(answer);
    
    if(answer.length() == 0) answer = "a";
    
    if(answer.length() > 15){ 
        if(answer[14] == '.') answer = answer.substr(0, 14);
        else answer = answer.substr(0, 15);
    }

    while(answer.length() < 3)
        answer += answer.back();

    return answer;
}