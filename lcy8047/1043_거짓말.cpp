#include <iostream>
#include <map>
#include <set>

using namespace std;

int people_count;
int party_count;
map<int, set<int>*> table;
bool *know_truth;
bool *know_truth_party;

void InitTable( void )
{
    for ( int i = 0; i < party_count; i ++ ) {
        int comming_people_count;
        cin >> comming_people_count;
        table.emplace( i, new set<int> );
        bool is_party_truth = false;
        for ( int j = 0; j < comming_people_count; j ++ ) {
            int people_num;
            cin >> people_num;
            
            if ( know_truth[people_num] ) {
                is_party_truth = true;
            }
            table[i]->insert( people_num );
        }

        if ( is_party_truth ) {
            know_truth_party[i] = true;
            for ( auto n : *table[i] ) {
                know_truth[n] = true;
            }
        }
    }

    for ( int i = 0; i < party_count; i ++ ){
        for ( auto it : table ) {
            bool is_party_truth = false;
            for ( auto n : *it.second ) {
                if ( know_truth[n] ) {
                    is_party_truth = true;
                    break;
                }
            }
            if ( is_party_truth ) {
                know_truth_party[it.first] = true;
                for ( auto n : *it.second ) {
                    know_truth[n] = true;
                }
            }
        }    
    }
}

int main(void)
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> people_count >> party_count;

    know_truth = new bool[people_count + 1];
    fill( know_truth, know_truth + people_count + 1, false );
    know_truth_party = new bool[party_count];
    fill( know_truth_party, know_truth_party + party_count, false );

    int known_truth_people_count;
    cin >> known_truth_people_count;
    for ( int i = 0; i < known_truth_people_count; i ++ ) {
        int people_num;
        cin >> people_num;
        know_truth[people_num] = true;
    }

    InitTable();

    if ( known_truth_people_count == 0 ) {
        cout << party_count << "\n";
        return 0;
    }

    int result = 0;
    for ( int i = 0; i < party_count; i ++ ) {
        if ( !know_truth_party[i] ) {
            result ++;
        }
    }

    cout << result << "\n";

    return 0;
}