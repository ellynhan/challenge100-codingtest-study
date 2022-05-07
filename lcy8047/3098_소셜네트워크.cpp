#include <iostream>
#include <vector>

using namespace std;

/*
1은 2~n 과, 2는 3~n .. 과 같은 방식으로 친구 신청.
친구신청 가능한지 여부 판단. ( 친구 아님 && 친구의 친구 )
친구아님 -> 테이블 확인
친구갱신 -> 친구신청가능하면 갱신( 각 사람마다 한번씩만 하고 break ) : solve함수 내부 동작
모두 친구가 되었는지 확인. -> 남은 친구 수 count해서 0이 되면 break; : solve내부
친구의 친구인지 판단. -> 테이블 확인
친구의 친구갱신 -> 친구 갱신때 같이 갱신( 친구 신청한사람의 친구에 대해 모두 바꿔줌 ) : solve 내부
친구 목록 테이블 - bool 2차원 배열
친구의 친구 목록 테이블 - bool 2차원 배열
*/

int n;
bool **friends;
bool **f_of_f;
uint32_t remain_friend_count;

bool is_all_friends( void )
{
    for ( int i = 1; i <= n; ++ i ) {
        for ( int j = 1; j <= n; ++ j ) {
            if ( ! friends[i][j] ) {
                return false;
            }
        }
    }

    return true;
}

uint32_t solve( void )
{
    vector< pair<int,int> > submit;
    uint32_t days = 0;
    vector<uint32_t> new_relation;
    while ( true ) {
        if ( is_all_friends() ) {
            break;
        }
        for ( int i = 1; i <= n; ++ i ) {
            for ( int j = i + 1; j <= n; ++ j ) {
                if ( !friends[i][j] && f_of_f[i][j] ) {
                    submit.emplace_back( i, j );
                }
            }
        }
        new_relation.push_back( submit.size() );
        for ( auto it : submit ) {
            int a = it.first;
            int b = it.second;
            friends[a][b] = true;
            friends[b][a] = true;
            for ( int i = 1; i <= n; ++ i ) {
                if ( friends[b][i] ) {
                    f_of_f[a][i] = true;
                    f_of_f[i][a] = true;
                }
                if ( friends[a][i] ) {
                    f_of_f[b][i] = true;
                    f_of_f[i][b] = true;
                }
            }
        }
        submit.clear();
        days ++;
    }

    cout << days << "\n";
    for ( auto it : new_relation ) {
        cout << it << "\n";
    }
    return days;
}

int main( void )
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    cin >> n;
    friends = new bool*[n + 1];
    f_of_f = new bool*[n + 1];
    for ( int i = 1; i <= n + 1; ++ i ) {
        friends[i] = new bool[n + 1];
        f_of_f[i] = new bool[n + 1];
        fill( friends[i], friends[i] + n + 1, false );
        fill( f_of_f[i], f_of_f[i] + n + 1, false );
        friends[i][i] = true;
    }

    int m;
    cin >> m;
    for ( int i = 0; i < m; ++ i ) {
        int a;
        int b;
        cin >> a >> b;

        friends[a][b] = true;
        friends[b][a] = true;
    }

    for ( int i = 1; i <= n; ++ i ) {
        for ( int j = 1; j <= n; ++ j ) {
            if ( friends[i][j] ) {
                for ( int k = 1; k <= n; ++ k ) {
                    if ( friends[j][k] ) {
                        f_of_f[i][k] = true;
                        f_of_f[k][i] = true;
                    }
                    if ( friends[i][k] ) {
                        f_of_f[j][k] = true;
                        f_of_f[k][j] = true;
                    }
                }
            }
        }
    }

    solve();

    return 0;
}