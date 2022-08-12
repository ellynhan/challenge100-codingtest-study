#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    // bool answer = false;
    int stackTop = 0;
    
    // if(s[0] == ')') return false;
    for(char c : s){
        if(stackTop < 0) return false;
        if(c == '(')
            stackTop++;
        else 
            stackTop--;
        // else {
            // if(stackTop != 0)
            //     stackTop--; 
        // }
    }
    // if(stackTop == 0) answer = true;
    // return answer;
    return stackTop == 0;
}