#include <iostream>
#include <set>
#include <stack>

using namespace std;

int main()
{
    string S;

    cin >> S;

    set<char> box;

    int open_count = 0;
    int close_count = 0;

    stack<set<char>> st;
    st.push(set<char>());

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '(')
        {
            st.push(set<char>());
        }
        else if (S[i] == ')')
        {
            for (auto &c : st.top())
            {
                box.erase(c);
            }
            st.pop();
        }
        else
        {
            if (box.count(S[i]))
            {
                cout << "No" << endl;
                return 0;
            }

            st.top().insert(S[i]);
            box.insert(S[i]);
        }
    }

    cout << "Yes" << endl;

    return 0;
}
