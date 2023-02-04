#include <iostream>

using namespace std;

int main()
{
    int N;
    string S;

    cin >> N >> S;

    bool n = false;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'n')
        {
            n = true;
            cout << S[i];
            continue;
        }

        if (n)
        {
            if (S[i] == 'a')
                cout << "y";
        }

        cout << S[i];

        n = false;
    }

    cout << endl;

    return 0;
}
