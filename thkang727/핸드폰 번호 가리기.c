#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* phone_number) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(phone_number);
    char* answer = (char*)malloc(20);
    strcpy(answer, phone_number);
    for(int i=0; i < len - 4; i++ ){
        answer[i] = '*';
    }
    printf("%s",answer);
    return answer;
}
