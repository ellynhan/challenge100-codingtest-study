#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    string answer = "";
    map<string, int> myMap;
    myMap["zero"] = 0;
    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;
    myMap["four"] = 4;
    myMap["five"] = 5;
    myMap["six"] = 6;
    myMap["seven"] = 7;
    myMap["eight"] = 8;
    myMap["nine"] = 9;
    
    string tmp = "";
    for(char c: s) {
        if('0' <= c && c <= '9'){
            answer += c;
        } 
        else{
          tmp += c;
        } 
        
        if(myMap.find(tmp) != myMap.end()) {
            answer += to_string(myMap[tmp]);
            tmp = "";
        }
    }
    
    return stoi(answer);
}
