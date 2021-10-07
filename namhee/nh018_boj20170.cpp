#include <iostream>
#include <algorithm>

using namespace std;

int dice1[7];
int dice2[7];
int gcd(int a, int b);

int main() {
	// 1. INPUT DATA 
    for (int i = 0; i < 6; i++)
       cin >> dice1[i];
    for (int i = 0; i < 6; i++)
       cin >> dice2[i];

	// 2. GET WIN NUM of DICE1
    sort(dice2, dice2 + 6);

    int winDice1 = 0;
    for (int i = 0; i < 6; i++) {
       for (int j = 0; j < 6; j++) {
          	if (dice1[i] > dice2[j])
            	winDice1++;
 	        else break;
        }
    }

	// 3. OUTPUT DATA - fraction(probability of the first player winning.)
    int gcdValue = gcd(winDice1, 36);
    cout << winDice1/gcdValue << "/" << 36/gcdValue;
}

int gcd(int a, int b) {
   while (b != 0) {
      int r = a % b;
      a = b;
      b = r;
   }
   return a;
}
