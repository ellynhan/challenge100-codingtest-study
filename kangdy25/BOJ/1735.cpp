// 분수 합

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int A1, B1, A2, B2, copyB1, copyB2;
    int GCD, LCM, molecule, copyLCM, copyMolecule;
    cin >> A1 >> B1;
    cin >> A2 >> B2;
    copyB1 = B1;
    copyB2 = B2;
    
    // 최대공약수를 구하는 과정
    while (B1 >= 1 && B2 >= 1) {
        if (B1 < B2) {
            B2 %= B1;
        } else {
            B1 %= B2;
        }
    }
    
    // 통분 과정 1
    if (B1 >= 1) {
        LCM = (B1 * (copyB1 / B1) * (copyB2 / B1));
        molecule = (A1 * (LCM / copyB1)) + (A2 * (LCM / copyB2));
        copyLCM = LCM;
        copyMolecule = molecule;
        // 통분 이후, 다시 기약분수로 만들기 위해 최대공약수를 구하는 과정
        while (copyLCM >= 1 && copyMolecule >= 1) {
            if (copyLCM < copyMolecule) {
                copyMolecule %= copyLCM;
            } else {
                copyLCM %= copyMolecule;
            }
        }
        // 다시 최대공약수를 구한 이후, 약분하는 과정
        if (copyLCM >= 1) {
            GCD = copyLCM;
            if (molecule % GCD == 0 && LCM % GCD == 0) {
                cout << molecule / GCD << " " << LCM / GCD;
            }
        } else {
            GCD = copyMolecule;
            if (molecule % GCD == 0 && LCM % GCD == 0) {
                cout << molecule / GCD << " " << LCM / GCD;
            }
        }
    } 
    // 통분 과정 2
    else {
        LCM = (B2 * (copyB1 / B2) * (copyB2 / B2));
        molecule = (A1 * (LCM / copyB1)) + (A2 * (LCM / copyB2));
        copyLCM = LCM;
        copyMolecule = molecule;
        // 통분 이후, 다시 기약분수로 만들기 위해 최대공약수를 구하는 과정
        while (copyLCM >= 1 && copyMolecule >= 1) {
            if (copyLCM < copyMolecule) {
                copyMolecule %= copyLCM;
            } else {
                copyLCM %= copyMolecule;
            }
        }
        // 다시 최대공약수를 구한 이후, 약분하는 과정
        if (copyLCM >= 1) {
            GCD = copyLCM;
            if (molecule % GCD == 0 && LCM % GCD == 0) {
                cout << molecule / GCD << " " << LCM / GCD;
            } else {
                cout << molecule << " " << LCM;
            }
        } else {
            GCD = copyMolecule;
            if (molecule % GCD == 0 && LCM % GCD == 0) {
                cout << molecule / GCD << " " << LCM / GCD;
            } else {
                cout << molecule << " " << LCM;
            }
        }
    }
}