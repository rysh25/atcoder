#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    stack<char> stk;
    stack<char> stk2;
    for (char c : S)
    {
        if (c == '(')
        {
            stk.push(c);
        }
        else if (c == ')')
        {
            if (!stk.empty() && stk.top() == '(')
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }
        else
        {
            stk.push(c);
        }
    }
    string res = "";
    while (!stk.empty())
    {
        res = stk.top() + res;
        stk.pop();
    }
    cout << res << endl;
    return 0;
}
