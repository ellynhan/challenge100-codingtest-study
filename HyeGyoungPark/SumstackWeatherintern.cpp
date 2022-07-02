#include <iostream>
#include <stdio.h>

using namespace std;

int main(void){

    int n,k;

    cin >> n >> k;

    int* su = new int[n];
    int* sum = new int[n];


    for(int i=0; i<n; i++){
        scanf("%d",&su[i]);
    }

    for(int i=0; i<n; i++){
        if(i==0) { sum[i] = su[i]; }
        else { sum[i] = sum[i-1]+su[i]; }
    }


    int premax = -100;

    for(int i=0; i<n-k; i++){
        if(premax < sum[i+k] - sum[i]){
            premax = sum[i+k] - sum[i];
        }
    }


    int now = 0;
    for(int i=0; i<k; i++){
        now+=su[i];
    }

    if(premax<now) premax = now;

    cout << premax;

    delete[] su;
    delete[] sum;

    return 0;

}
