#include <iostream>

using namespace std;

int main()
{
    string S;

    cin >> S;

    for (int i = S.length() - 1; i >= 0; i--)
    {
        if (S[i] == 'a')
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
