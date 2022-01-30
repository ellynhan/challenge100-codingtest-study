#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
bool cmp(string A, string B)
{
    if(A.length() <= B.length()){
        if(A.length() == B.length())
            return A < B;    
        else 
            return true;  
    }
    else return false;
}

int main(){
    int N;
    vector<string> strArr;
    cin >> N;
    while(N--){
        string str;
        cin >> str;
        strArr.push_back(str);
    }
    sort(strArr.begin(), strArr.end(), cmp);
    strArr.erase(unique(strArr.begin(),strArr.end()),strArr.end());
    for(int i=0; i<strArr.size(); i++)
    {
        cout << strArr[i] << '\n';
    }
}
