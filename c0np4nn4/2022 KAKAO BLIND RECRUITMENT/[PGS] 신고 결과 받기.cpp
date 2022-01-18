vector<string> split(string& str, const char delimiter) {
    istringstream iss(str);
    string buffer;
    
    vector<string> result;
    while (getline(iss, buffer, delimiter)) {
        result.push_back(buffer);
    }
    
    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    bool report_info[1001][1001];
    int report_count[1001];
    
    int user_len = id_list.size();
    
    answer.resize(user_len, 0);

    
    // 1. count how many time each user is reported
    for (int i = 0; i < report.size(); i++) {
        vector<string> report_str = split(report[i], ' ');
        
        vector<string>::iterator from, to;
        from = find(id_list.begin(), id_list.end(), report_str[0]);
        to = find(id_list.begin(), id_list.end(), report_str[1]);
        
        int i_from, i_to;
        i_from = distance(id_list.begin(), from);
        i_to = distance(id_list.begin(), to);
        
        if (report_info[i_from][i_to] != true) {
            report_info[i_from][i_to] = true;
            report_count[i_to]++;
        }
    }
    
    
    // 2. check if user reported the banned one
    for (int i = 0; i < user_len; i++) {
        int cnt = 0;
        for (int j = 0; j < user_len; j++) {
            if (report_info[i][j] && report_count[j] >= k) {
                // answer[i]++;
                cnt++;
            }
        }
        answer[i] = cnt;
    }
    
    return answer;
}
