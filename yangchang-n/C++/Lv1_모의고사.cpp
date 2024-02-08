#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {

    int num_1_score = 0, num_2_score = 0, num_3_score = 0;
    vector<int> num_1 = {1, 2, 3, 4, 5};
    vector<int> num_2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> num_3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> answer;
    
    int prob_count = answers.size();
    int index_1 = 0, index_2 = 0, index_3 = 0;
    
    for (int i = 0; i < prob_count; ++i)
    {
        if (index_1 == num_1.size()) index_1 -= num_1.size();
        if (index_2 == num_2.size()) index_2 -= num_2.size();
        if (index_3 == num_3.size()) index_3 -= num_3.size();
        
        if (answers[i] == num_1[index_1]) num_1_score++;
        if (answers[i] == num_2[index_2]) num_2_score++;
        if (answers[i] == num_3[index_3]) num_3_score++;
        
        index_1++;
        index_2++;
        index_3++;
    }
    
    int max_score = max({num_1_score, num_2_score, num_3_score});
    if (max_score == num_1_score) answer.push_back(1);
    if (max_score == num_2_score) answer.push_back(2);
    if (max_score == num_3_score) answer.push_back(3);
    
    return answer;
}
