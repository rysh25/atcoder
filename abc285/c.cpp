#include <iostream>

using namespace std;

int main()
{
    string S;

    cin >> S;

    long long res = 0;
    long long d = 1;
    for (int i = S.length() - 1; i >= 0; i--)
    {
        res += (S[i] - 'A' + 1) * d;
        d *= 26;
    }

    cout << res++ << endl;

    return 0;
}
