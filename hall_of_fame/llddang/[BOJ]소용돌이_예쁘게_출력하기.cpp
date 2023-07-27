#include <iostream>

using namespace std;

int main(){
    int is, js, ie, je;
    cin >> is  >> js >> ie >> je;
    is += 5000; ie += 5000;
    js += 5000; je += 5000;
    
    int arr[50][10] = {0, };
    int di[] = {0, -1, 0, 1};
    int dj[] = {1, 0, -1, 0};

    int i=5000, j=5000, k;
    int num=1, repeat=1, dir=0, cnt=0;
    while(arr[0][0] == 0     || arr[ie-is][0] == 0 ||
          arr[0][je-js] == 0 || arr[ie-is][je-js] == 0){
            if(is <= i && i <= ie && js <= j && j <= je){
                arr[i-is][j-js] = num;
            }
            
            num++;
            cnt++;
            i += di[dir];
            j += dj[dir];
            
            if(cnt == repeat){
                cnt = 0;
                dir = (dir + 1) % 4;
                if(dir % 2 == 0) repeat++;
            }
    }
    
    int len = 0;
    string temp;
    for(i=0; i<=ie-is; i++){
        for(j=0; j<=je-js; j++){
            temp = to_string(arr[i][j]);
            if(len < temp.size()) len = temp.size();
        }
    }
    
    for(i=0; i<=ie-is; i++){
        for(j=0; j<=je-js; j++){
            temp = to_string(arr[i][j]);
            for(k=0; k<len-temp.size(); k++) cout << " ";
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
