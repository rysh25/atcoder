#include <iostream>

using namespace std;

int main()
{
    string S;

    cin >> S;
    for (int i = 0; i < S.length() / 2; i++)
    {
        char tmp = S[2 * i];
        S[2 * i] = S[2 * i + 1];
        S[2 * i + 1] = tmp;
    }

    cout << S << endl;

    return 0;
}
