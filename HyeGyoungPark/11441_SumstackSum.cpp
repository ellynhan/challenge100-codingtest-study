#include <iostream>
#include <stdio.h>

using namespace std;

int main(void){

    int n,su,m;

    scanf("%d",&n);

    int* sum = new int[n+1];

    sum[0] = 0;

    for(int i=1; i<n+1; i++){
        scanf("%d",&su);
        sum[i] = sum[i-1]+su;
    }

    scanf("%d",&m);

    for(int i=0; i<m; i++){
        int a,b;

        scanf("%d %d", &a, &b);
        printf("%d\n",sum[b] - sum[a - 1]);
    }

    delete[] sum;

    return 0;

}
