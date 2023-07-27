#include <iostream>
using namespace std;

int main(){
    int num; cin >> num;
    int i, tmp, cnt=0;
    int five=0, two=0;
    for(i=1; i<=num; i++){
        tmp = i;
        while(tmp % 2 == 0){
            two++;
            tmp /= 2;
        }
        while(tmp % 5 == 0){
            five++;
            tmp /= 5;
        }
    }
    cout << min(five, two);
}
