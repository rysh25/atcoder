#include <iostream>

using namespace std;

int main()
{
    string S;

    cin >> S;

    if (S.length() != 8)
    {
        cout << "No" << endl;
        return 0;
    }

    if (S[0] < 'A' || S[0] > 'Z')
    {
        cout << "No" << endl;
        return 0;
    }

    if (S[1] < '1' || S[1] > '9')
    {
        cout << "No" << endl;
        return 0;
    }

    if (S[S.length() - 1] < 'A' || S[S.length() - 1] > 'Z')
    {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 2; i < S.length() - 2; i++)
    {
        if (S[i] < '0' || S[i] > '9')
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
