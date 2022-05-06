#include <iostream>
#include <stdio.h>

using namespace std;

int main(void){
    int n, k, now=0,premax=0;

    cin >> n >> k;

    int* pie = new int[n+n-1];
    int* sum = new int[n+n-1];

    for(int i=0; i<n; i++){
        scanf("%d",&pie[i]);
    }
    for(int i=n; i<n+n-1; i++){
        pie[i] = pie[i-n];
    }

    for(int i=0; i<n+n-1; i++){
        if(i==0) { sum[i] = pie[i]; }
        else { sum[i] = sum[i-1]+pie[i]; }
    }

    for(int i=0; i<n+n-1-k; i++){
        if(sum[i+k]-sum[i] > premax) { premax = sum[i+k]-sum[i]; }
    }

    for(int i=0; i<k; i++){
        now+=pie[i];
    }
 
    if(premax<now) premax = now;


    cout << premax;

    delete[] pie;
    delete[] sum;

    return 0;
    
}
