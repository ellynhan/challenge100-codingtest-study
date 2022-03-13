#include<iostream>
using namespace std;

int cntArr[10001];   // 최대 값이 10000인게 핵심
int main()
{
    int N;
    cin>>N;
    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        cntArr[t]++;
    }
    for(int i=1; i<10001; i++) 
        for(int j=0; j<cntArr[i]; j++)
            cout << i << '\n';
    
}