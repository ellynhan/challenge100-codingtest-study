#include<iostream>
#include<string>
#include<deque>
using namespace std;
int N;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    bool isReverse, isError;
    cin >> T;
    while(T--){
        string op, input_arr;
        deque<int> dq;
        cin >> op >> N >> input_arr;
        isReverse = isError = false;
        string num;
        for(int i=0; i<input_arr.size(); i++){
            if(isdigit(input_arr[i])){
                num += input_arr[i];
            }
            else{
                if(num.size() > 0){
                    dq.push_back(stoi(num));
                    num = "";
                }
            }
        }
        for(int i=0; i<op.size(); i++){
            if(op[i] == 'R') isReverse = !isReverse;
            else if(op[i] == 'D')
            {
                if(dq.empty()) {
                    cout << "error\n";
                    isError = true;
                    break;
                }
                else{
                    if(isReverse) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }
        if(!isError){
            cout << '[';
            if(isReverse){
                for(auto it = dq.rbegin(); it != dq.rend(); it++)
                    if(it == dq.rend()-1) cout << *it;
                    else
                        cout << *it << ",";
                
            }
            else{            
                for(auto it = dq.begin(); it != dq.end(); it++)
                    if(it == dq.end()-1) cout << *it;
                    else
                        cout << *it << ",";
            }
            cout << "]\n";
        }
    }
}