#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> result;
    for(char iter : s){
        if(result.empty() || result.top() != iter)
            result.push(iter);
        else
            result.pop();
    }
    
    return result.empty() ? 1 : 0;
}