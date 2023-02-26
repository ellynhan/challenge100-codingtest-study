#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int L;
    vector<int> vec;
    int num;
    int tmp, i;
    
    cin >> L;
    for(i=0; i<L; i++){
        cin >> tmp;
        vec.push_back(tmp);
    }
    cin >> num;
    
    sort(vec.begin(), vec.end());
    
    for(i=0; i<L; i++){
        if(vec[i] == num){
            cout << 0;
            return 0;
        }
        if(vec[i] > num)
            break;
    }
    
    int start = vec[i-1] + 1;
    int end = vec[i] - 1;
    int sum = (num - start) * (end - num + 1) + (end - num);
    
    cout << sum;
    
    return 0;
}
