#include <bits/stdc++.h>

using namespace std;

int arr[6][3];
bool flag;

bool flag_check(){
    for (auto & i : arr){
        for (int k : i){
            if (k != 0) {
                return false;
            }
        }
    }

    return true;
}

void dfs(int idx, int next, int depth){
    if(idx == 5 && depth == 15){
        if(flag_check()) flag = true;
        return;
    }
    
    if(arr[idx][0] > 0 && arr[next][2] > 0){
        arr[idx][0]--;
        arr[next][2]--;
        dfs(idx, next + 1, depth + 1);
        arr[idx][0]++;
        arr[next][2]++;
    }
    
    if(arr[idx][1] > 0 && arr[next][1] > 0){
        arr[idx][1]--;
        arr[next][1]--;
        dfs(idx, next + 1, depth + 1);
        arr[idx][1]++;
        arr[next][1]++;
    }
    
    if(arr[idx][2] > 0 && arr[next][0] > 0){
        arr[idx][2]--;
        arr[next][0]--;
        dfs(idx, next + 1, depth + 1);
        arr[idx][2]++;
        arr[next][0]++;
    }
    
    if(idx < 5) {
        dfs(idx + 1, idx + 2, depth);
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 4; i++) {
        memset(arr, 0, sizeof(arr));
        
        int c = 0;
        for(int k = 0; k < 18; k++){
            cin >> arr[k/3][c++];
            
            if(c == 3) {
                c = 0;
            }
        }
        
        dfs(0, 1, 0);
        
        cout << (flag ? 1 : 0) << ' ';
        flag = false;
    }
}

