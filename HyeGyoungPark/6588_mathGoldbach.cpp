#include <iostream>
#include <cmath>

using namespace std;

bool sosu(int num) {
	if (num < 2) return false;
	int a = (int) sqrt(num);
	for (int i = a; i >= 2; i--) if (num % i == 0) return false;
	return true;
}

int main(void) {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(0);
    int su,flag=0;

    cin >> su;

    while(su!=0){
        for (int i=su; i>2; i--){
            if(sosu(i)){
                if(sosu(su-i)){
                    cout << su << " = " << su-i << " + " << i << "\n";
                    flag=1;
                }
            }
            if(flag==1){
                break;
            }
        }

        if(flag==0){
            cout << "Goldbach's conjecture is wrong.\n";
        }

        cin >> su;
        flag = 0;
    }

	return 0;
}
