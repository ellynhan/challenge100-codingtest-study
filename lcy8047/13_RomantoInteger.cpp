class Solution {
public:
    int romanToInt(string s) {
        char prev_char = 0;
        int result = 0;
        for ( auto c : s )
        {
            switch ( c )
            {
                case 'I':
                {
                    result += 1;
                    break;
                }
                case 'V':
                {
                    if ( prev_char == 'I' )
                    {
                        result += 3;
                    }
                    else
                    {
                        result += 5;
                    }
                    break;
                }
                case 'X':
                {
                    if ( prev_char == 'I' )
                    {
                        result += 8;
                    }
                    else
                    {
                        result += 10;
                    }
                    break;
                }
                case 'L':
                {
                    if ( prev_char == 'X' )
                    {
                        result += 30;
                    }
                    else
                    {
                        result += 50;
                    }
                    break;
                }
                case 'C':
                {
                    if ( prev_char == 'X' )
                    {
                        result += 80;
                    }
                    else
                    {
                        result += 100;
                    }
                    break;
                }
                case 'D':
                {
                    if ( prev_char == 'C' )
                    {
                        result += 300;
                    }
                    else
                    {
                        result += 500;
                    }
                    break;
                }
                case 'M':
                {
                    if ( prev_char == 'C' )
                    {
                        result += 800;
                    }
                    else
                    {
                        result += 1000;
                    }
                    break;
                }
                default:
                {
                    assert( false );
                    break;
                }
            }
            prev_char = c;
        }
        return result;
    }
};