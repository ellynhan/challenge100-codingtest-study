#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, first_num, gcd = 1;
    scanf("%d", &n);

    //int arr_nu[n], arr_nd[n];

    for(int i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (i==0)   first_num = tmp;
        else {
            for(int j=1; j<= first_num && j <= tmp; j++){
                if(first_num % j ==0 && tmp % j == 0)
                    gcd = j;

            }
            printf("%d/%d \n", first_num/gcd, tmp/gcd);
        }

    }


/*
    for(int i=1; i<n; i++) {
        printf("%d\n", arr_n[i]/arr_n[0]);
    }
*/

    return 0;
}
