/*
    자료구조 실버4
    균형잡힌 세상.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true){
        string input;
        getline(cin, input);
        stack<char> s;
        bool ans = true;
        if(input.length()==1 && input[0]=='.') {break;}
        for(int i=0; i < input.length();i++){
            if(input[i]=='('|| input[i]=='['){
                s.push(input[i]);
               }
            if(input[i]==')'){
                if(s.empty()||s.top()=='['){ans = false;}
                else {s.pop();}
            }
            if(input[i]==']'){
                if(s.empty()||s.top()=='('){ans = false;}
                else {s.pop();}
            }
        }
    if(s.empty() && ans==true) {cout<< "yes" <<endl;}
    else {cout << "no" <<endl;}

    }
    return 0;
}
