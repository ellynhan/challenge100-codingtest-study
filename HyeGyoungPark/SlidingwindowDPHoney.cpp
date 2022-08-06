#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
    long long n,m,cnt=0,monmax=0;

    cin >> n >> m;

    long long int* money = new long long int[n]();
    long long int* sum = new long long int[n]();

    for(int i=0; i<n; i++){
        scanf("%d",&money[i]);

        if(i<m){
            sum[cnt]+=money[i];
        }
        else{
            cnt++;
            sum[cnt]=sum[cnt-1]-money[cnt-1];
            sum[cnt]+=money[i];
        }
        if(sum[cnt]>monmax){
            monmax=sum[cnt];
        }
    }

    printf("%lld", monmax);

    delete[] money;
    delete[] sum;

    return 0;
}
