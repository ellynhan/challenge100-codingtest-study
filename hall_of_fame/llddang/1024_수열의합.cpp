#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum, num; cin >> sum >> num;
    while(sum >= num*(num-1) / 2){
        int tmp = sum - num*(num-1)/2;
        if (num > 100) break;
        if(tmp % num != 0){
            num++;
            continue;
        }
        int first = tmp / num;
        for(int i=0; i<num; i++){
            cout << first + i << " ";
        }
        break;
    }
    if(sum < num*(num-1) / 2 || num > 100)
        cout << "-1";
}
