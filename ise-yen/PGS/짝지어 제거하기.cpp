#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    if(s.length() == 1) return 0;
    stack<char> st;
    st.push(s[0]);
    for(int i = 1; i < s.length(); i++){
        if(st.empty() || st.top() != s[i]) st.push(s[i]);
        else st.pop();
    }
    
    return st.empty() ? 1 : 0;
}
