#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int brokens[11] = {0};
int dest, broken;
vector<int> validNum;
int result, resultDif=-1;

int calDif(int num) {
    int dif = dest - num;
    if(dif<0){
        return -dif;
    }else{
        return dif;
    }
}

void bfs() {
    queue<int> q;
    for(int i=0; i<validNum.size(); i++){
        q.push(validNum[i]);
    }
    while(!q.empty()){
        int currNum = q.front();
        q.pop();
        int currLen = to_string(currNum).length();
        int destLen = to_string(dest).length();
        if((currLen >= destLen -1 && currLen <= destLen +1)||currNum == 0){
            if(resultDif == -1){
                resultDif = calDif(currNum);
                result = currNum;
            }else{
                if(resultDif > calDif(currNum)){
                    resultDif = calDif(currNum);
                    result = currNum;
                }
            }
        }
        if(currLen < destLen +1 && currNum != 0){
            for(int i=0; i<validNum.size(); i++){
                q.push(currNum*10 + validNum[i]);
            }
        }
    }
}


int main(){
    cin >> dest >> broken;
    
    for(int i=0; i<broken; i++){
        int num;
        cin >> num;
        brokens[num] = 1;
    }

    for(int i=0; i<10; i++){
        if(brokens[i]==0){
            validNum.push_back(i);
        }
    }

    int dif = calDif(100);
    int len = to_string(dest).length();

    if(broken == 0){
        if(dif > len){
            cout<<len;
        }else{
            cout<<dif;
        }
    } else if(broken == 10){
        cout<<dif;
    }else{
        bfs();
        int resultLen = to_string(result).length();
        int totalPush = resultDif + resultLen;
        if(dif > totalPush){
            cout<<totalPush;
        }else{
            cout<<dif;
        }
    }    
}

//반례
//1. 9 -> 11 / 11 -> 9와 같이 숫자 길이 다른 경우 고려할 것
//2. 고장난게 0개일때와 10개일 때를 고려할 것 
//3. 0일때를 아주 유심히 고려할 것
