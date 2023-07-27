#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct Point{
    int x;
    int y;
    Point(int xx, int yy) :x(xx), y(yy) {};
};

int N, M; 
vector<int> check;
vector<int> exist;
vector<Point> chicken;
vector<Point> house;

int find_min_len(int x, int y){
    int i;
    int result = 1000;
    for(i=0; i<exist.size(); i++){
        int index = exist[i];
        int len = abs(chicken[index].x - x) + abs(chicken[index].y - y);
        result = min(result, len);
    }
    return result;
}

int main(){
    cin >> N >> M;
    int i, j, tmp;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            cin >> tmp;
            if(tmp == 1){
                house.push_back(Point(i, j));
            } else if(tmp == 2){
                chicken.push_back(Point(i, j));
            }
        }
    } // 입력 다 받기!

    int result = 0;
    if(chicken.size() <= M){
        for(i=0; i<chicken.size(); i++){
            exist.push_back(i);
        }
        for(i=0; i<house.size(); i++){
            result += find_min_len(house[i].x, house[i].y);
        }
        cout << result;
        return 0;
    }

    int cnt = 0;
    int minLen = -1;
    while(1){
        if(exist.size() == M){
            int len = 0;
            for(i=0; i<house.size(); i++){
                len += find_min_len(house[i].x, house[i].y);
            }
            if(minLen == -1 || minLen > len){
                minLen = len;
            }

            exist.pop_back();
            while(cnt > chicken.size() - (M - exist.size())){
                if(exist.empty()) break;
                cnt = exist.back() + 1;
                exist.pop_back();

            }
            if(cnt > chicken.size() - (M - exist.size())) break;
            exist.push_back(cnt);
            cnt++;
        }

        if(exist.size() < M){
            exist.push_back(cnt);
            cnt++;
        }
    }
    cout << minLen;
    return 0;
}
