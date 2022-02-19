#include <iostream>
#include <cmath>
using namespace std;


int *arr = new int[1000000];

void Eratosche(int num) {

    for (int i=2; i<=num; i++) {
        arr[i] = i;
    }

    for (int i=2; i<=num; i++) {
        if (arr[i]==0)
            continue;

        for (int j=i+i; j<=num; j+=i) {
            arr[j] = 0;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,su,ans;

    cin >> n;

    for(int i=0; i<n; i++){
        ans = 0;
        cin >> su;
        Eratosche(su);
        for (int i=su; i>=su/2; i--){
            if(arr[i]!=0){
                if(arr[su-i]!=0){
                    ans++;
                }
            }
        }

        cout << ans << "\n";
        }

    delete[] arr;
	return 0;
}
