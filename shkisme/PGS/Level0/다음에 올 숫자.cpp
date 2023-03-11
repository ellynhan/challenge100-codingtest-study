#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int num1 = common.at(1) - common.at(0);
    int num2 = common.at(2) - common.at(1);
    
    bool isMult;
    
    if (num2 == num1){
        isMult = false;
    }
    else{
        isMult = true;
    }
    
    if (isMult){
        answer = common.at(common.size() - 1) * (common.at(1) / common.at(0));
    }
    else{
        answer = common.at(common.size() - 1) + num1;
    }
    
    return answer;
}
