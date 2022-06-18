#include<bits/stdc++.h>

using namespace std;

int answer, N, F;

int main() {
    cin >> N >> F;

    int result = (N/100)*100/F;
    if((result*F)/100 == N/100) answer = (result*F)%100;
    else { answer = ((result+1)*F)%100; }

    printf("%02d", answer);
    return 0;
}
