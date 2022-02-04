#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int num,i,cnt1,cnt2, price=0;

    cin >> num;

    int *dairy = new int[num]();

    for(i=0; i<num; i++){
        cin >> dairy[i];
    }

    sort(dairy, dairy+num, greater<>());

    cnt1 = num/3;
    cnt2 = num%3;

    for(i=0; i<cnt1; i++){
        price+=dairy[3*i]+dairy[3*i+1];
    }

    if(cnt2!=0){
        for(i=0; i<cnt2; i++){
            price+=dairy[num-1-i];
        }
    }

    cout << price;

    delete[] dairy;

    return 0;
}
