#include <vector>
#include <iostream>

using namespace std;

int CalcSquare( vector<int> *nums )
{
    int sum = 0;
    for ( auto n : *nums ) {
        sum += n * n;
    }
    return sum;
}

bool FindSquares( int count_of_square, int target )
{
    vector<int> nums;
    nums.resize( count_of_square );
    fill( nums.begin(), nums.end(), 1 );
    if ( CalcSquare( &nums ) == target ) {
        return true;
    }

    while ( CalcSquare( &nums ) < target ) {
        while( CalcSquare( &nums ) < target ) {
            nums[0] ++;
        }
        if ( CalcSquare( &nums ) == target ) {
            return true;
        }
        if ( count_of_square == 1 ) {
            return false;
        }
        nums[0] = 1;
        for ( int i = 1; i < count_of_square; i ++ ) {
            nums[i] ++;
            int square = CalcSquare( &nums );
            if ( square > target ) {
                if ( i == count_of_square - 1 ) {
                    return false;
                }
                nums[i] = 1;
            }
            else if ( square == target ) {
                return true;
            }
            else {
                break;
            }
        }
    }
    return false;
}

int Solve( int target )
{
    for ( int i = 1; i <= 4; i ++ ) {
        if ( FindSquares ( i, target ) ) {
            return i;
        }
    }
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << Solve( n ) << endl; 

    return 0;
}