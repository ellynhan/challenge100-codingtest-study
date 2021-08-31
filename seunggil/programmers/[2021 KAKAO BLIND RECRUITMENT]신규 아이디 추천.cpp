#include <string>
#include <vector>

using namespace std;

bool islower(char a) {
    return 'a' <= a && a <= 'z';
}

bool isUpper(char a) {
    return 'A' <= a && a <= 'Z';
}

bool isSpecialChar(char a) {
    return a == '.' || a == '-' || a == '_';
}

bool isNum(char a) {
    return '0' <= a && a <= '9';
}

bool allowChar(char a) {
    if (!(islower(a) || isSpecialChar(a) || isNum(a)))
        return false;
    return true;
}

string solution(string new_id) {

    //1
    for (char& iter : new_id)
        if (isUpper(iter))
            iter += 'a' - 'A';
    
    //2
    for (string::iterator iter = new_id.begin(); iter != new_id.end(); iter++)
        if (!allowChar(*iter))
            iter-- = new_id.erase(iter);
            
    //3
    string::iterator beforeIter = new_id.begin();
    for (string::iterator iter = ++new_id.begin(); iter != new_id.end();){
        if(*beforeIter == '.' && *iter == '.')
            iter = new_id.erase(iter);
        else{
            iter++;
            beforeIter++;
        }
    }
                
    //4
    if(new_id.front() == '.')
        new_id.erase(new_id.begin());
    if(new_id.back() == '.')
        new_id.erase(--new_id.end());
    
    //5
    if(new_id.length() == 0)
        new_id = "a";
    
    //6
    if(new_id.length() >= 16)
        new_id = new_id.substr(0,15);
    if(new_id.back() == '.')
        new_id.erase(--new_id.end());
    
    //7
    while(new_id.length() <= 2)
        new_id += new_id.back();

    return new_id;
}