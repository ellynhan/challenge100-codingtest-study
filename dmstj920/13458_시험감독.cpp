#include <iostream>

using namespace std;
int test[1000000];

int main()
{
    int num, i, first, second, chk;
    long long sum;
    
    cin >> num;
    sum = num;

    for(i=0; i<num; i++){
        cin >> test[i];
    }

    cin >> first >> second;

    for(i=0; i<num; i++){
        chk = (test[i] - first) % second;

        if(test[i] <= first) continue;
        else if(chk == 0){
            sum += (test[i] - first) / second;
        }
        else{
            sum += (test[i] - first) / second + 1;
        }
    }

    cout << sum;

    return 0;
}
