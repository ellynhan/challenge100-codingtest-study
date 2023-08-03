#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
int main()
{
    char buf[101];
    stack<char> opr;
    scanf("%s", buf);
    for(int i = 0 ; i < strlen(buf) ; i++)
    {
        if(buf[i] == '(')
        {
            opr.push(buf[i]);
        }
        else if(buf[i] == ')')
        {
            while(opr.top() != '(')
            {
                printf("%c", opr.top());
                opr.pop();
            }
            opr.pop();
        }
        else if(buf[i] == '*' || buf[i] == '/')
        {
            if(opr.empty())
            {
                opr.push(buf[i]);
            }
            else
            {
                while(!opr.empty() && (opr.top() == '*' || opr.top() == '/'))
                {
                    printf("%c", opr.top());
                    opr.pop();
                }
                opr.push(buf[i]);
            }
        }
        else if(buf[i] == '+' || buf[i] == '-')
        {
            if(opr.empty())
            {
                opr.push(buf[i]);
            }
            else
            {
                while(!opr.empty())
                {
                    if(opr.top() == '(')
                    {
                        break;
                    }
                    printf("%c", opr.top());
                    opr.pop();
                }
                opr.push(buf[i]);
            }
        }
        else
        {
            printf("%c", buf[i]);
        }
    }
    while(!opr.empty())
    {
        if(opr.top() != '(' )
        {
            printf("%c", opr.top());
        }
        opr.pop();
    }
    return 0;
}
