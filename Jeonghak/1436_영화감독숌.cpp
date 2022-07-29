#include<iostream>

using namespace std;

int main()
{
    int N, cnt = 1, num=666;
    cin >> N;

    while(cnt < N){
        num++;
        string strNum = to_string(num);
        if(strNum.find("666") != -1) cnt++;
    }
    cout << num;
}