#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string S;
    cin >> S;

    bool isValid = false;

    int firstB = -1;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'B')
        {
            if (firstB == -1)
            {
                firstB = i % 2;
            }
            else if (firstB != i % 2)
            {
                isValid = true;
                break;
            }
        }
    }
    if (!isValid)
    {
        cout << "No" << endl;
        return 0;
    }

    bool openR = false;
    bool foundKind = false;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'R')
        {
            if (!openR)
            {
                openR = true;
            }
            else if (foundKind)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
        if (S[i] == 'K')
        {
            if (openR)
            {
                foundKind = true;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
