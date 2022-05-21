/*
    2609 최대공약수와 최소공배수
    실버5 수학
*/


#include <iostream>

using namespace std;

int main()
{
    int n,m,up,down,divans,timans;
    cin >> n >> m;
    if(n>m){
        up = n;
        down = m;
    }
    else if(n==m){
        cout << n<<endl;
        cout << n<<endl;
        return 0;
    }
    else{
        up = m;
        down = n;
    }
    for(int i=down;i>=1;i--){
        if(up%i==0 && down%i==0){
            divans=i;
            break;
        }
    }
    int index=up;
    while(true){
        if(index%up==0 && index%down==0){
            timans=index;
            break;
        }
        index++;
    }
    cout<< divans<<'\n';
    cout<< timans<<'\n';
    return 0;
}
