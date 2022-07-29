#include<iostream>

using namespace std;

int main()
{
    int N, result=0;
    cin >> N;
    for(int i=1; i<=N; i++){
        int currI = i;
        while((currI % 5 == 0)) {
            if(currI == 0) break;
            result++;
            currI /= 5;
        }
    }
    cout << result;
}