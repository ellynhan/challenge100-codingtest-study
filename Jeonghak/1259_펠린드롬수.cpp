#include<iostream>
#include<string>
using namespace std;

int main(){
    int count, strLength;
    string str;

    while(true){
        count=0;
        cin >> str;
        strLength = str.size();
        if(str == "0") break;
        for(int i=0; i<strLength/2; i++){
            if(str[i]==str[strLength-i-1]) count++;
        }
        if(count == strLength/2) cout << "yes\n";
        else cout << "no\n";
    }
}
