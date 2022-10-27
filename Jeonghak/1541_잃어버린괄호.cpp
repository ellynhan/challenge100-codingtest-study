#include<iostream>
#include<string>
using namespace std;

int main()
{
    int sum = 0;
    string exp, num;
    bool flag = false;
    cin >> exp;
    for(int i=0; i<=exp.size(); i++){
        char c = exp[i];
        if(!isdigit(c) || i == exp.size()){
            if(flag)
                sum -= stoi(num);
            else sum += stoi(num);
            if(c == '-') flag = true;
            num = "";
        }
        else{
            num += c;
        }
    }
    cout << sum;
}