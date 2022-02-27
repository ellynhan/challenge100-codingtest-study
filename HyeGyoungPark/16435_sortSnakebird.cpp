#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
    int n,L,now,cnt=0;
    int fruit[10000] = {};

    cin >> n >> L;
    now = L;

    for(int i=0; i<n; i++){
        scanf("%d",&fruit[i]);
    }

    sort(fruit,fruit+n);

    for(int i=0; i<n; i++){
        if(now>=fruit[i]) now++;
    }

    cout << now;

    return 0;
}
