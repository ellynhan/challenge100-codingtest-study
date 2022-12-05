#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> gears;
int twelve[4] = {0, };
bool isVisit[4] = {false, };
int rotation[4] = {0, };

void Rotate() {
    for(int i=0; i<4; i++) {
        int direction = rotation[i];
        if(direction == 1) { 
            twelve[i] -= 1;
            if(twelve[i] < 0)
                twelve[i] = 7;
        }
        if(direction == -1){
            twelve[i] += 1;
            if(twelve[i] > 7)
                twelve[i] = 0;
        }
    }
}

void setRotateDirection(int gear, int direction) {
    rotation[gear] = direction;
    isVisit[gear] = true;

    if(gear + 1 < 4 && !isVisit[gear + 1]) {
        if(gears[gear][(twelve[gear] + 2) % 8] == gears[gear+1][(twelve[gear + 1] + 6) % 8]
            || direction == 0) {
            setRotateDirection(gear + 1, 0);
        } else {
            setRotateDirection(gear + 1, -direction);
        }
    }

    if(gear - 1 >= 0 && !isVisit[gear - 1]){
        if(gears[gear][(twelve[gear] + 6) % 8] == gears[gear-1][(twelve[gear - 1] + 2) % 8]
            || direction == 0) {
            setRotateDirection(gear - 1, 0);
        } else {
            setRotateDirection(gear - 1, -direction);
        }
    }
}

int getPoint() {
    int result = 0;
    int point = 1;

    for(int i=0; i<4; i++) {
        if(gears[i][twelve[i]] == '1') {
            result += point;
        };
        point *= 2;
    }
    return result;
}

int main() {
    int rotate_count, gear, direction, answer = 0;

    for(int i=0; i<4; i++) {
        string input;
        cin >> input;
        gears.push_back(input);
    }
    cin >> rotate_count;

    for(int i=0; i<rotate_count; i++) {
        cin >> gear >> direction;
        setRotateDirection(gear - 1, direction);
        Rotate();
        for(int i=0; i<4; i++) isVisit[i] = false;
    }

    cout << getPoint();
}