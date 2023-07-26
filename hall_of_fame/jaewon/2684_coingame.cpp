#include <iostream>
using namespace std;

string coinSeq[8]={"TTT","TTH","THT","THH","HTT","HTH","HHT","HHH"};
int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        int cnt [8]={0};
        string result;
        cin >> result;
        string tmp = result.substr(0,2);
        for(int i=2; i<40; i++){
            tmp += result[i];
            for(int j=0; j<8; j++){
                if(tmp==coinSeq[j]){
                    cnt[j]+=1;
                    break;
                }
            }
            tmp = tmp.substr(1,3);
        }
        for(int i=0; i<8; i++){
            cout<<cnt[i]<<" ";
        }
        cout<<endl;
    }
}
