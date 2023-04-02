#include <iostream>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;

    char prev = ' ';
    for (int i = 0; i < N; i++)
    {
        if (prev == S[i])
        {
            cout << "No" << endl;
            return 0;
        }
        prev = S[i];
    }

    cout << "Yes" << endl;

    return 0;
}
