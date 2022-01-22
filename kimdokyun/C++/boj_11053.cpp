#include<stdio.h>

int main() {
    int N,max=0;
    int nums[1001] = {0,};
    int values[1001] = {0,};
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        scanf("%d",&nums[i]);
        values[i]=0;
        for(int j=0;j<i;j++) {
            if(nums[j]<nums[i] && values[i]<values[j]+1) {
                values[i] = values[j]+1;
            }
            if(max < values[i]) {
                max = values[i];
            }
        }
    }
    printf("%d",max);
}