#include <string>
#include <vector>
#include <list>
#include <set>
#include <cmath>

using namespace std;


void cal(list<string>& expr, string oper) {
    list<string>::iterator beforeIter = expr.begin();
    list<string>::iterator nowIter = ++expr.begin();
    list<string>::iterator nextIter = nowIter;
    nextIter++;

    while (nextIter != expr.end()) {
        if (*nowIter == oper) {
            if (*nowIter == "*")
                *nowIter = to_string((stoll(*beforeIter) * stoll(*nextIter)));

            else if (*nowIter == "+")
                *nowIter = to_string((stoll(*beforeIter) + stoll(*nextIter)));

            else if (*nowIter == "-")
                *nowIter = to_string((stoll(*beforeIter) - stoll(*nextIter)));

            beforeIter = expr.erase(beforeIter);
            nextIter = expr.erase(nextIter);
            nowIter++;
            if(nextIter != expr.end())
                nextIter++;
        }
        else {
            beforeIter++;
            nowIter++;
            nextIter++;
        }
    }
}

long long solution(string expression) {
    long long answer = 0;
    list<string> result;
    set<char> usingOperator;
    string num = "";
    for (char a : expression) {
        if ('0' <= a && a <= '9')
            num += a;
        else {
            result.push_back(num);
            num = "";
            result.push_back(string(1, a));
            usingOperator.insert(a);
        }
    }
    result.push_back(num);

    set<string> operatorPriority;
    
    
    if(usingOperator.size() == 3){
        for(char iter1 : usingOperator){
            string priority = string(1,iter1);
            for(char iter2 : usingOperator){
                if(iter2 != iter1){
                    priority += string(1,iter2);
                    for(char iter3: usingOperator)
                        if(iter3 != iter1 && iter3 != iter2){
                            priority += string(1,iter3);
                            operatorPriority.insert(priority);
                            priority.pop_back();
                        }
                    priority.pop_back();
                }
            }
            priority.pop_back();
        }
    }else if(usingOperator.size() == 2){
        for(char iter1 : usingOperator){
            string priority = string(1,iter1);
            for(char iter2 : usingOperator){
                if(iter2 != iter1){
                    priority += string(1,iter2);
                    operatorPriority.insert(priority);
                    priority.pop_back();
                }
            }
            priority.pop_back();
        }
    }else{
        operatorPriority.insert(string(1,*usingOperator.begin()));
    }
    

    
    for(string iter : operatorPriority){
        list<string> copyResult = result;
        for(char o : iter)
            cal(copyResult,string(1,o));
        long long reward = abs(stoll(copyResult.front()));
        if(answer < reward){
            answer = reward;
        }   
    }

    return answer;
}