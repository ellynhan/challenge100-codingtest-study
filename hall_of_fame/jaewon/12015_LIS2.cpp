#include <iostream>
using namespace std;
int arr[1000001]={0};
int dp[1000001]={0}; //len-1

int divide(int start, int end, int value){
    while(end-start>0){
        int mid = (start+end)/2;
        if(dp[mid]<value){
            start = mid +1;
        }else if(dp[mid]>value){
            end = mid;
        }else{
            return -1;
        }
    }
    return end;
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dp[0]=arr[0];
    int len = 0;
    for(int i=1; i<n; i++){
        if(dp[len]<arr[i]){
            len++;
            dp[len]=arr[i];
        }else{
            int ret = divide(0,len,arr[i]);
            if(ret!=-1)dp[ret]=arr[i];
        }
    }
    cout<<len+1;
}
