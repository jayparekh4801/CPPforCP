#include <iostream>
#include <stack>

using namespace std;

bool checkBalancing(string exp)
{
    stack<char> s;

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            s.push(exp[i]);
            continue;
        }

        if (s.empty())
        {
            return false;
        }

        char top = s.top();
        s.pop();

        switch (top) {
            case '{':
                if (exp[i] == ']' || exp[i] == ')')
                {
                    return false;
                }
                break;

            case '(':
                if (exp[i] == ']' || exp[i] == '}')
                {
                    return false;
                }
                break;

            case '[':
                if (exp[i] == ')' || exp[i] == '}')
                {
                    return false;
                }
                break;
        }
    }
    return true;
}

int main()
{
    string exp;
    cin >> exp;

    bool result = checkBalancing(exp);
    if (result)
    {
        cout << "BALANCED";
    }
    else
    {
        cout << "NOT BALANCED";
    }
    return 0;
}