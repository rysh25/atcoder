// #include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main()
{
    int A, B;
    cin >> A >> B;

    string S;
    cin >> S;

    bool yes = true;
    if (S.length() == A + B + 1 &&
        S.substr(A, 1) == "-")
    {
        for (auto &c : S.replace(A, 1, ""))
        {
            if (!std::isdigit(c))
            {
                yes = false;
                break;
            }
        }
    }
    else
    {
        yes = false;
    }

    if (yes)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
