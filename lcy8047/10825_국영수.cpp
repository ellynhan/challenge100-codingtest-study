#include <iostream>
#include <set>

using namespace std;

struct info
{
    string name;
    int kor;
    int eng;
    int math;
};

struct Compare
{
    bool operator() ( const info &a, const info &b ) const 
    {
        if ( a.kor == b.kor )
        {
            if ( a.eng == b.eng )
            {
                if ( a.math == b.math )
                {
                    return a.name < b.name;
                }
                return a.math > b.math;
            }
            return a.eng < b.eng;
        }
        return a.kor > b.kor;
    }
};

int main( void )
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    set<info, Compare> s;

    int n;
    cin >> n;
    for ( int i = 0; i < n; ++ i )
    {
        string name;
        int kor;
        int eng;
        int math;
        cin >> name >> kor >> eng >> math;
        info tmp_info;
        tmp_info.name = name;
        tmp_info.kor = kor;
        tmp_info.eng = eng;
        tmp_info.math = math;
        s.insert( tmp_info );
    }
    for ( auto e : s )
    {
        cout << e.name << "\n";
    }

    return 0;
}