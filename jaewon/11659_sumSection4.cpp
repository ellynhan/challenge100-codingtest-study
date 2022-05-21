#include <iostream>
#define ioboost ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
//1020 ~ 25

int sum[100001] = {0};

int main(){
    ioboost;
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        sum[i+1] += sum[i]+tmp;
    }
    for(int i=0; i<m; i++){
        int start, end, total = 0;
        cin >> start >> end;
        total = sum[end]-sum[start-1];
        cout<<total<<'\n';
    }
}