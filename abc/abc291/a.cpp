#include <iostream>

using namespace std;

int main()
{
    string S;

    cin >> S;

    int res = 0;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] < 'a')
            res = i;
    }

    cout << res + 1 << endl;

    return 0;
}
