#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, j, count, max=0, res=0;
    int box[1000] = {0,};
    int countList[1000] = {0,};

    scanf("%d", &num);

    for(i=0; i<num; i++){
        scanf("%d", &box[i]);
        countList[i] = 1;
    }

    for(i=1; i<num; i++){
        for(j=0; j<i; j++){
            if(box[i] > box[j]){
                count = countList[i];
                count += countList[j];
            }

            if(max < count){
                max = count;
            }

        }

        countList[i] = max;

        if(res < countList[i]){
            res = countList[i];
        }

        count = 1;
        max = 1;
    }



    printf("%d", res);


    return 0;
}
