#include<iostream>
#include<stack>
#include<string>
using namespace std;

// ][] 일때 yes 나오는 문제 있었음.
int main()
{
    while(true){
        stack<char> v;
        string str;
        getline(cin, str);
        if(str == ".")
            break;
        for(int i = 0; i<str.size(); i++){
            if(str[i] == '(' || str[i] == '[') v.push(str[i]);
            if(str[i]==')'){
                if(!v.empty() && v.top() == '(')
                    v.pop();
                else {v.push(' '); break;}
            }  
            if(str[i]==']'){
                if(!v.empty() && v.top() == '[')
                    v.pop();
                else v.push(str[i]);
            }  
        }
        if(v.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}