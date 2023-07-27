#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

string trim(string str){
    string temp="";
    for(int i=1; i<str.size()-1; i++){
        temp+=str[i];
    }
    return temp;
}

int main(){
    int testCase;
    cin >> testCase;
    while(testCase--){
        string cmd, arr;
        int n, numOfD=0;
        cin >> cmd;
        for(int i=0; i<cmd.length(); i++){
            if(cmd[i]=='D'){
                numOfD++;
            }
        }
        cin >> n >> arr;
        if(numOfD>n){
            cout<<"error\n";
        }else{
            arr = trim(arr);
            stringstream ss(arr);
            string tmp;
            deque<int> numberArr;
            while (getline(ss, tmp, ',')) {
                numberArr.push_back(stoi(tmp));
            }

            bool flag = false;
            for(int i=0; i<cmd.length(); i++){
                if(cmd[i]=='R'){
                    flag = !flag;
                }else{
                    if(flag){
                        numberArr.pop_back();
                    }else{
                        numberArr.pop_front();
                    }
                }
            }

            cout<<"[";
            if(numberArr.size()>0){
                if(flag){
                    while(numberArr.size()!=1){
                        cout<<numberArr.back()<<",";
                        numberArr.pop_back();
                    }
                    cout<<numberArr.back();
                }else{
                    while(numberArr.size()!=1){
                        cout<<numberArr.front()<<",";
                        numberArr.pop_front();
                    }
                    cout<<numberArr.front();
                }
            }
            cout<<"]\n";
        }
    }
}
