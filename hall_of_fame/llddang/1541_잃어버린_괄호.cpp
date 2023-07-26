#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str; cin >> str;
    vector<int> num;
    vector<char> exe;

    string s;
    for(int i=0; i<=str.size(); i++){
        if(i == str.size()){
            num.push_back(stoi(s));
        } else if(str[i] == '-' || str[i] == '+'){
            num.push_back(stoi(s));
            s = "";
            exe.push_back(str[i]);
        } else {
            s += str[i];
        }
    }

    for(int i=0; i<exe.size(); i++){
        if(exe[i] == '+'){
            num[i] += num[i+1];
            exe.erase(i + exe.begin());
            num.erase(i + 1 + num.begin());
            i--;
        }
    }

    for(int i=1; i<num.size(); i++){
        num[0] -= num[i];
    }

    cout << num[0];
}
