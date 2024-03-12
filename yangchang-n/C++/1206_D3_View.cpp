#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T = 10;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int answer = 0;
        int building_count;
        cin >> building_count;

        vector<int> building_num(building_count);
        for (int num = 0; num < building_count; ++num)
        {
            cin >> building_num[num];
        }

        for (int check = 2; check < building_count - 2; ++check)
        {
            int mid_building = building_num[check];
            vector<int> side_building = {building_num[check - 2], building_num[check - 1], building_num[check + 1], building_num[check + 2]};
            int side_max = *max_element(side_building.begin(), side_building.end());

            if (mid_building > side_max)
            {
                answer += mid_building - side_max;
            }
        }

        cout << '#' << test_case << ' ' << answer << endl;
    }

    return 0;
}
