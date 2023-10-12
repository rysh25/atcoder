#include <iostream>

using namespace std;

int main()
{
    string S;
    cin >> S;

    bool res = true;
    int count_c = 0;
    int count_lower = 0;

    for (int i = 0; i < S.size(); i++)
    {
        if ('a' <= S[i] && S[i] <= 'z')
        {
            count_lower++;
        }

        if (2 <= i && i <= S.size() - 2 && S[i] == 'C')
        {
            count_c++;
        }
    }

    if (S[0] == 'A' && count_c == 1 && S.size() - count_lower == 2)
    {
        cout << "AC" << endl;
    }
    else
    {
        cout << "WA" << endl;
    }

    return 0;
}
