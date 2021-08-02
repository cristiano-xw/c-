#include<iostream>
#include<cstring>
#include"linkstack.h"
using namespace std;
//思路 检测到左边的括号我就入栈，监测到右边的括号，我就和栈顶的括号进行比较
bool Match(char * s)
{
    linkstack<char>tmps;
    char tmpch;

    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
        {
            tmps.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(tmps.empty())
            {
                return false;
            }
            else if(tmps.Top(tmpch),tmpch=='(')
            {
                tmps.pop();
            }
            else 
            {
                return false;
            }
        }

        else if(s[i]==']')
        {
            if(tmps.empty())
            {
                return false;
            }

            else if(tmps.Top(tmpch),tmpch=='[')
            {
                tmps.pop();
            }

            else
            {
                return false;
            }
        }

        else if(s[i]=='}')
        {
            if(tmps.empty())
            {
                return false;
            }

            else if(tmps.Top(tmpch),tmpch=='{')
            {
                tmps.pop();
            }

            else
            {
                return false;
            }
        }
    }

    if(tmps.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}