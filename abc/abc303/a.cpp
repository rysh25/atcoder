#include <iostream>

using namespace std;

int main()
{
    int N;
    string S, T;

    cin >> N;
    cin >> S >> T;

    bool ans = true;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == T[i] ||
            (S[i] == '1' && T[i] == 'l') ||
            (S[i] == 'l' && T[i] == '1') ||
            (S[i] == '0' && T[i] == 'o') ||
            (S[i] == 'o' && T[i] == '0'))
        {
            // Do nothing
        }
        else
        {
            ans = false;
            break;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
