#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int timeToMin(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3,2));
    return h * 60 + m;
}

string minToTime(int m) {
    int h = m / 60;
    m = m % 60;
    string H = to_string(h);
    string M = to_string(m);
    if(h < 10) H = "0" + H;
    if(m < 10) M = "0" + M;
    return H + ":" + M;
}

// n회 t분 간격 m명의 승객, 모든 차를 승객이 타면 00:00
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "09:00";
    string curr_bus = "09:00";
    int curr_table_index = 0;
    int remain = n * m;
    sort(timetable.begin(), timetable.end());

    for(int i=0; i<n; i++) {
        int curr_passenger= 0;
        for(int j=0; j<m; j++) {
            if(curr_table_index > timetable.size() - 1) {
                break;
            }
            if(timetable[curr_table_index] > curr_bus || remain == 0) 
                break;
            curr_passenger++;
            curr_table_index++;
            remain--;
        }
        // 현재 버스가 꽉 찼으면 마지막 탑승객 -1분에 도착해야 함
        if(curr_passenger == m) {
            answer = minToTime(timeToMin(timetable[curr_table_index - 1]) - 1);
        } else {
            answer = curr_bus;
        }
        curr_bus = minToTime(timeToMin(curr_bus) + t);
    }
    
    return answer;
}