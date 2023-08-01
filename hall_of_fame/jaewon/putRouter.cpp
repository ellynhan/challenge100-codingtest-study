#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(void) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int house, wifi;
    cin >> house >> wifi;

    vector<int> x;

    for(int i=0; i<house; i++){
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    sort(x.begin(), x.end());
    
    int low = 1;
    int high =  x[house-1]-x[0];
    int answer = 0;
    while(low<=high){
        int cnt = 1;
        int mid = (low+high)/2;
        int tmp = x[0];
        for(int i=0; i<house; i++){
            if(x[i]-tmp>=mid){
                tmp = x[i];
                cnt ++;
            }
        }
        if(cnt>=wifi){
            low = mid+1;
            answer = max(answer, mid);
        }else{
            high = mid-1;
        }
    }
    cout<<answer;
}  

