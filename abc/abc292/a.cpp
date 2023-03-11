#include <iostream>

using namespace std;

int main()
{
    string S;

    cin >> S;

    string t;
    for (int i = 0; i < S.length(); i++)
    {
        t.push_back(S[i] - ('a' - 'A'));
    }

    cout << t << endl;

    return 0;
}
