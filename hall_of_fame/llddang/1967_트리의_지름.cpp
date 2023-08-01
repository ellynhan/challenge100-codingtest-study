#include <iostream>
#include <vector>
using namespace std;

int N;
struct NODE{
    int parent=0;
    vector<int> child;
    vector<int> childFee;
    int fee;
};
NODE arr[10001];
vector<int> leaf;

int main(){
    cin >> N;
    int s, e, f;
    for(int i=1; i<N; i++){
        cin >> s >> e >> f;
        arr[s].child.push_back(e);
        arr[s].childFee.push_back(f);

        arr[e].parent = s;
        arr[e].fee = f;
    }

    for(int i=1; i<=N; i++){
        if(arr[i].child.empty()) leaf.push_back(i);
    }

    int curr, prev, fee;
    for(int i=0; i<leaf.size(); i++){
        fee=0;
        prev = leaf[i];
        curr = arr[prev].parent;
        fee += arr[prev].fee;
        while(curr != 0){
            bool childInput = false, moreValue = false;
            for(int j=0; j<arr[curr].child.size(); j++){
                if(arr[curr].child[j] == prev && arr[curr].childFee[j] < fee){
                    arr[curr].childFee[j] = fee;
                    childInput = true;
                }
                if(fee < arr[curr].childFee[j]) moreValue = true;
                if(childInput && moreValue) break;
            }
            if(moreValue) break;
            fee += arr[curr].fee;
            prev = curr;
            curr = arr[curr].parent;
        }
    }

    int answer = 0;
    for(int i=1; i<=N; i++){
        int value1=0, value2=0;
        for(int j=0; j<arr[i].childFee.size(); j++){
            if(value1 < arr[i].childFee[j]){
                value2 = value1;
                value1 = arr[i].childFee[j];
            } else if(value2 < arr[i].childFee[j]){
                value2 = arr[i].childFee[j];
            }
        }
        answer = max(answer, value1 + value2);
    }

    cout << answer;
}
