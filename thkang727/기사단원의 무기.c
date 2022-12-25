#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int number, int limit, int power) {
    int answer = 0;
    int arr[number];
    
    for(int i =0; i<number;i++) arr[i]=0;
    for(int i=1; i<=number; i++){
        int tmp = 0;
        for(int j=1; j<=i; j++){
            if(i%j==0) tmp++;
        }
        arr[i-1] = tmp;
    }
    for(int i =0; i<number; i++){
        if(arr[i] > limit) answer+=power;
        else answer+=arr[i];
    }
    return answer;
}
