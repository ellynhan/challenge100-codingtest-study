#include<stdio.h>

int main() {
    int N,nums[1000],increase[1000]={},decrease[1000]={},result=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&nums[i]);
    for(int i=0;i<N;i++) {
        increase[i] = decrease[N-i-1] = 1;
        for(int j=0;j<i;j++) {
            increase[i] = nums[j] < nums[i] && increase[j]+1 > increase[i]?increase[j]+1:increase[i];
            decrease[N-i-1] = nums[N-j-1] < nums[N-i-1] && decrease[N-j-1]+1 > decrease[N-i-1]?decrease[N-j-1]+1:decrease[N-i-1];
        }
    }
    for(int i=0;i<N;i++) result = result < increase[i]+decrease[i]-1?increase[i]+decrease[i]-1:result;
    printf("%d",result);
}