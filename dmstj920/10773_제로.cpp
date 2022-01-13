#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num, i, money, sum=0;
    vector<int> data;
    cin >> num;

    for(i=0; i<num; i++){
        cin >> money;

        if(money == 0){
            data.pop_back();
        }

        else{
            data.push_back(money);
        }
    }

    if(data.size() == 0)
        cout << 0;

    else{
        for(i=0; i < data.size(); i++){
            sum += data[i];
        }
        cout << sum;
    }
}

