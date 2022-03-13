#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int K, sum=0;
    vector<int> v;
    cin >> K;

    for(int i=0; i<K; i++){
        int t;
        cin >> t;
        if(t==0) v.pop_back();
        else v.push_back(t);
    }
    for(auto i= v.begin(); i!=v.end(); i++) sum += *i;
    cout << sum;
}