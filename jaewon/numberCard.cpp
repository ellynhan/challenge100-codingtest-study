#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int upper_bound(vector<int>& v, int target){
    int start = 0, end = v.size()-1;
    while(start<end){
        int mid = (start+end)/2;
        if(v[mid]>target){
            end = mid;
        }else{
            start = mid + 1;
        }
    }
    return end;
}

int lower_bound(vector<int>& v, int target){
    int start = 0, end = v.size()-1;
    while(start<end){
        int mid = (start+end)/2;
        if(v[mid]>=target){
            end = mid;
        }else{
            start = mid+1;
        }
    }
    return end;
}

int main(void) {
    int n, m;
    cin >> n;
    vector<int> v;
    int maxValue = -10000000;
    for(int i=0; i<n; i++){
        int tmp; 
        cin >> tmp;
        v.push_back(tmp);
        if(maxValue<tmp){
            maxValue = tmp;
        }
    }
    sort(v.begin(), v.end());
    cin >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        if(tmp==maxValue){
            cout<<upper_bound(v,tmp)-lower_bound(v,tmp)+1<<" ";
        }else{
            cout<<upper_bound(v,tmp)-lower_bound(v,tmp)<<" ";
        }
        
    }
}

