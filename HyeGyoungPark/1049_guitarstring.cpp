#include <iostream>
#include <algorithm>

using namespace std;

int main(void){

    int brand[51] = {0,};
    int single[51] = {0,};

    int need, n, pay=0;

    cin >> need >> n;

    for(int i=0; i<n; i++){
        cin >> brand[i] >> single[i];
    }

    sort(brand, brand+n);
    sort(single, single+n);

    if(need>6){
            
        if(need%6==0){
            pay = need*single[0];
            for(int i=0; i<n; i++){
                if(pay > (need/6)*brand[i]){
                    pay = (need/6)*brand[i];
                }
            }
        }
            
        else{
            pay = (need%6)*single[0] + (need/6)*brand[0];

            if(single[0]*need < pay){
                pay = single[0]*need;
            }

            for(int i=0; i<n; i++){
                if(pay > (((need/6)+1)*brand[i])){
                    pay = (((need/6)+1)*brand[i]);
                }
            }
        }
    }

    else{
        pay = need * single[0];

        for(int i=0; i<n; i++){
            if(pay > brand[i]){
                pay = brand[i];
            }
        }
    }

    cout << pay;

    return 0;
}
