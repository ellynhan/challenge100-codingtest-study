#include <iostream>
#include <random>

using namespace std;

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 99);

    int random_num = distrib(gen);
    int input_num;

    cout << "Guess the integer between 1 and 99\n";
    while (1)
    {   
        cout << "Input : ";
        cin >> input_num;
        if (input_num >= 100 || input_num <= 0)
        {
            cout << "Out of range\n";
        }
        else if (input_num == random_num)
        {
            cout << "Correct!\n";
            break;
        }
        else if (input_num > random_num)
        {
            cout << "Down\n";
        }
        else
        {
            cout << "Up\n";
        }
    }

    return 0;
}
