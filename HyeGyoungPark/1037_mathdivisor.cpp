#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int n;

    cin >> n;

    int *su = new int[n];
    for(int i=0; i<n; i++){
        scanf("%d",&su[i]);
    }

    sort(su,su+n);

    cout << su[0]*su[n-1];

    delete[] su;
    
    return 0;

}
