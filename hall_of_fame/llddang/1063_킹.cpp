#include <iostream>
using namespace std;

string move(string pin, string movement){
    if(pin[0] == 'A' && movement.find("L") != string::npos ||
       pin[0] == 'H' && movement.find("R") != string::npos || 
       pin[1] == '1' && movement.find("B") != string::npos ||
       pin[1] == '8' && movement.find("T") != string::npos )
            return pin;
    
    if(movement.find("R") != string::npos)
        pin[0] = pin[0]+1;
        
    if(movement.find("L") != string::npos)
        pin[0] = pin[0]-1;
        
    if(movement.find("B") != string::npos)
        pin[1] = pin[1]-1;
        
    if(movement.find("T") != string::npos)
        pin[1] = pin[1]+1;
    
    return pin;
}

int main(){
    string king, stone;
    int N;
    cin >> king >> stone >> N;
    string nKing, nStone;
    
    string movement;
    while(N--){
        cin >> movement;
        
        nKing = move(king, movement);
        nStone = move(stone, movement);
        
        if(nKing != stone){
            king = nKing;
        } else if(stone != nStone){
            king = nKing;
            stone = nStone;
        }
    }
    
    cout << king << "\n" << stone;
}
