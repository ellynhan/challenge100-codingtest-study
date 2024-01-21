#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string str) {
    vector<string> answer;
    istringstream istrstream(str);
    string tmp;
    while(getline(istrstream, tmp, ' ')){
        answer.push_back(tmp);
    }
    return answer;
}
