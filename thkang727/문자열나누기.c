#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int slen = strlen(s);
    for(int i=0; i< slen; i++){
        int xlen =1;
        int notXlen =0;
        char x = s[i];
        i++;
        while(1){
            if (xlen == notXlen){
                answer++;
                i--;
                break;
            }
            if (s[i] != x){
                notXlen++;
            }
            else xlen++;
            i++;
        }
    }
    return answer;
}
